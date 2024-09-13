classroom = {0: [1, 2], 1: [0, 5], 2: [0], 3: [6], 4: [], 5: [1], 6: [3]}
friendships = []
studentFriendshipIndices = {}

def addStudentToFriendships(student, groupIndex = None):
    if student not in studentFriendshipIndices:
        if groupIndex == None:
            groupIndex = len(friendships)
            friendships.append({student})
        else:
            friendships[groupIndex].add(student)
        studentFriendshipIndices[student] = groupIndex

for student, friends in classroom.items():
    addStudentToFriendships(student)
    for friend in friends:
        addStudentToFriendships(friend, studentFriendshipIndices[student])

print(friendships)
