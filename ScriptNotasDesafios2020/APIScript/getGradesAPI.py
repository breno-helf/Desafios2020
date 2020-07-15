import requests
import sys

URL_PREFIX = 'https://vjudge.net/contest/rank/single/'

contests = open('contests.txt').readline().split(' ')
students = open('students.txt').readline().split(' ')

studentGrade = {}
studentNumber = {}
contestTitle = {}

# Optimistic upsolving time, may increase grades by a little. 
# Its assuming the upsolving only took a week 
def calculateUpsolvingTime(contestData):
    return contestData['length'] / 1000 - 60 * 60 * 168

def checkAndIncludeStudents(contestData):
    for ID, names in contestData['participants'].items():
        for name in names:
            name = name.lower()
            ID = int(ID)
            if name in students and ID not in studentGrade:
                studentGrade[ID] = {}
                studentNumber[name] = ID

# Gets sucessfull submission for each problem with minimum submission time
def getBestSuccessfullSubmissions(contestData):
    successfullSubmissions = {}
    for submission in contestData['submissions']:
        studentID, problemNumber, AC, submissionTime = submission[:4]
        if not AC or studentID not in studentGrade:
            continue
        if studentID not in successfullSubmissions:
            successfullSubmissions[studentID] = {}
        if problemNumber not in successfullSubmissions[studentID]:
            successfullSubmissions[studentID][problemNumber] = submissionTime
        else:
            successfullSubmissions[studentID][problemNumber] = min(successfullSubmissions[studentID][problemNumber], submissionTime)
    return successfullSubmissions
    
def gradeSubmissions(submissions, contest, upsolvingTime):
    for studentID, problemsWithSubmissionTime in submissions.items():
        studentGrade[studentID][contest] = 0.0
        for submissionTime in problemsWithSubmissionTime.values():
            studentGrade[studentID][contest] += 1 if submissionTime <= upsolvingTime else 0.5

for contest in contests:
    contestUrl = URL_PREFIX + contest
    contestData = requests.get(contestUrl).json()

    upsolvingTime = calculateUpsolvingTime(contestData)
    checkAndIncludeStudents(contestData)

    successfullSubmissions = getBestSuccessfullSubmissions(contestData)
    gradeSubmissions(successfullSubmissions, contest, upsolvingTime)
    contestTitle[contest] = contestData['title']

print('--------', end='\t')
for contest, title in contestTitle.items():
    print(title, end='\t')
print('')

for student in students:
    print(student, end='\t')
    for contest in contests:
        if contest not in studentGrade[studentNumber[student]]:
            print(0, end='\t')
        else:
            print(studentGrade[studentNumber[student]][contest], end='\t')
    print('')

sys.stdout = open('grades.txt', 'w')

for student in students:
    for contest in contests:
        if contest not in studentGrade[studentNumber[student]]:
            print(0, end='\t')
        else:
            print(studentGrade[studentNumber[student]][contest], end='\t')
    print('')
