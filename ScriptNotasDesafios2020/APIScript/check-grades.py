grades = open('grades.txt')
old = open('old_grades.txt')

j = 0
cur_grades = grades.readline().split('\t')
while len(cur_grades) != 1:
    old_grades = old.readline().split('\t')
    old_grades = list(map(float, old_grades))
    cur_grades = list(map(float, cur_grades))
    assert len(cur_grades) == len(old_grades)
    for i in range(len(cur_grades)):
        if cur_grades[i] < old_grades[i]:
            print(j, i)
            assert false
    j += 1
    cur_grades = grades.readline().split('\t')
