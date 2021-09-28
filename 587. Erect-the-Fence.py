class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        def com(point1, point2, point3):
            x1,y1  = point1
            x2,y2 = point2
            x3,y3 = point3
            return (y3-y2)*(x2-x1) -(y2-y1)*(x3-x2)
        points = sorted(trees)
        upper = []
        lower = []
        for point in points:
            while len(upper)>=2 and com(upper[-2],upper[-1],point) > 0:
                upper.pop()
            while len(lower)>=2 and com(lower[-2],lower[-1],point) < 0:
                lower.pop()
            upper.append(tuple(point))
            lower.append(tuple(point))
        return list(set(upper+lower))
