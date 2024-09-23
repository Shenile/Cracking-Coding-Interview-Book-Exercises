def isSusbstring(string, substring):
    map = {}
    for s in string:
       if s in map:
           map[s] += 1
       else:
           map[s] = 1

    for s in substring:
        if s in map and map[s] > 1:
            map[s] -= 1
        else:
            return False
    return True

def isRotation(s1, s2):
    if len(s1) != len(s2):
        return False
    return isSusbstring(s1+s1, s2)


s1 = 'waterbottle'
s2 = 'elttobretaw'
print(isRotation(s1, s2))