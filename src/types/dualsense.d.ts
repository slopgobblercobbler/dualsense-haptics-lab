export interface ScePadTriggerEffectParam {
    mode: number;
    command: number;
    position: number;
    frequency: number;
    strength: number;
}

export interface ScePadTouchData {
    x: number;
    y: number;
    id: number;
    touching: boolean;
}

export interface ScePadMotionData {
    acceleration: { x: number; y: number; z: number };
    angularVelocity: { x: number; y: number; z: number };
    orientation: { x: number; y: number; z: number; w: number };
}
