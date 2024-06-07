def GetDegree(grapgh, vertrex) :
    if vertrex > len(grapgh) :
        print("vertex index is out of range!")
        return
    degree = 0
    for i in range(len(grapgh[vertrex])) :
        if grapgh[vertrex][i] != 0 :
            degree += 1
    return degree

g = [
    [0, 7, 6, 0, 0, 0, 0, 0],
    [7, 0, 0, 5, 0, 0, 0, 0],
    [6, 0, 0, 3, 0, 0, 0, 0],
    [0, 5, 3, 0, 0, 8, 0, 0],
    [0, 0, 0, 0, 0, 4, 2, 4],
    [0, 0, 0, 8, 4, 0, 7, 0],
    [0, 0, 0, 0, 2, 7, 0, 6],
    [0, 0, 0, 0, 4, 0, 6, 0]
]

print(GetDegree(g, 6))