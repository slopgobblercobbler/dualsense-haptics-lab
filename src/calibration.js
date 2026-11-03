// DualSense 6-Axis Motion Sensor Calibration
export class MotionCalibration {
    constructor(biasAccel = {x: 0, y: 0, z: 0}, biasGyro = {x: 0, y: 0, z: 0}) {
        this.bAccel = biasAccel;
        this.bGyro = biasGyro;
    }

    apply(raw) {
        return {
            accel: {
                x: raw.accel.x - this.bAccel.x,
                y: raw.accel.y - this.bAccel.y,
                z: raw.accel.z - this.bAccel.z
            },
            gyro: {
                x: raw.gyro.x - this.bGyro.x,
                y: raw.gyro.y - this.bGyro.y,
                z: raw.gyro.z - this.bGyro.z
            }
        };
    }
}
