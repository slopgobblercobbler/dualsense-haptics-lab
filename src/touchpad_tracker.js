// DualSense Touchpad Coordinate Normalization (1920x1080 resolution)
export class TouchpadTracker {
    static MAX_X = 1920;
    static MAX_Y = 1080;

    static normalize(rawX, rawY) {
        const clampedX = Math.max(0, Math.min(TouchpadTracker.MAX_X, rawX));
        const clampedY = Math.max(0, Math.min(TouchpadTracker.MAX_Y, rawY));
        return {
            x: clampedX,
            y: clampedY,
            normX: clampedX / TouchpadTracker.MAX_X,
            normY: clampedY / TouchpadTracker.MAX_Y
        };
    }

    static calculateDistance(p1, p2) {
        const dx = p1.x - p2.x;
        const dy = p1.y - p2.y;
        return Math.sqrt(dx * dx + dy * dy);
    }
}
