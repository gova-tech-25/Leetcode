class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // int xMin = xCenter - radius;
        // int xMax = xCenter + radius;

        // int yMin = yCenter - radius;
        // int yMax = yCenter + radius;

        // if(x2 < xMin || x1 > xMax) return false;
        // if(y2 < yMin || y1 > yMax) return false;

        int closeX = max(x1 , min(x2 , xCenter));
        int closeY = max(y1 , min(y2 , yCenter));

        int dx = closeX - xCenter;
        int dy = closeY - yCenter;

        return dx * dx + dy * dy <= radius * radius;
    }
};