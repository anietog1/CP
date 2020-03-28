import sys

class Canva(object):

    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.pegs = []

    def add_peg(self, peg):
        self.pegs.append(peg)


n = int(sys.stdin.readline())

canvas = []

for _ in range(n):
    line = sys.stdin.readline().split()
    l, r = int(line[0]), int(line[1])
    canvas.append(Canva(l, r))

p = int(sys.stdin.readline())
line = sys.stdin.readline().split()
pegs = list(map(int, line))

possible = True

for i in range(p):
    peg = pegs[i]
    for j in range(n):
        canva = canvas[j]
        if peg >= canva.left and peg <= canva.right:
            canva.add_peg(peg)
            if len(canva.pegs) > 2:
                possible = False
                break
        if peg < canva.left:
            break
    if not possible:
        break


if not possible:
    print('impossible')
else:

    npegs = []

    for i in range(len(canvas)):
        #for canva in canvas:
        canva = canvas[i]

        nnpegs = []

        if len(canva.pegs) == 0:
            exc = 0
            ex2 = 0
            if i > 0:
                if canvas[i - 1].right == canva.left:
                    exc = 1
            canva.pegs.append(canva.left + exc)
            if i < n - 1:
                if canvas[i + 1].left == canva.right:
                    if len(canvas[i + 1].pegs) < 2:
                        canvas[i + 1].pegs.append(canva.right)
                    else:
                        ex2 = 1
            canva.pegs.append(canva.right - ex2)

        elif len(canva.pegs) == 1:
            peg = canva.pegs[0]
            if peg == canva.right:
                exc = 0
                if i > 0:
                    if canvas[i - 1].right == canva.left:
                        exc = 1
                canva.pegs.append(canva.left + exc)
            else:
                ex2 = 0
                if i < n - 1:
                    if canvas[i + 1].left == canva.right:
                        if len(canvas[i + 1].pegs) < 2:
                            canvas[i + 1].pegs.append(canva.right)
                        else:
                            ex2 = 1
                canva.pegs.append(canva.right - ex2)

        #print(canva.left, canva.right, canva.pegs)
        npegs.extend(canva.pegs)

    npegs = set(npegs)
    #print(npegs)
    print(len(npegs) - len(pegs))
    print(' '.join(sorted([str(x) for x in npegs.difference(set(pegs))])))
