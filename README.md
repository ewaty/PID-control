## PID Control Project

# Descripion of the project

This project employs a PID and PD controller to drive the car in a simulator. The aim is to keep the car inside the track lanes on straight stretches and sharp turns.

# Effect of PID parameters

Kp - the parameter of proportional control. This element is responsible for correcting the error in the current iteration, in proportion to the error value. I have found that when I increase the constant Kp, the car reacts faster to rapid changes of target value, such as turns. However, its increase causes the car to overshoot and swivel more and it takes longer for the car to stabilize close to target value.

Kd - the parameter of derivative control. Parameter Kd is multiplied by the difference between the current error and that of the last iteration and the two are divided by the time step. It is a way to react to the rate of change of the error. When the error is increasing, this element increases the control signal. When the error is decreasing, it is decreasing the control signal thus "dampening" the car trajectory. When Kd is increased the car moves with less swivelling, in a more smooth manner.

Ki - the parameter of integral control. The constant Ki is multiplied by the sum of all errors from the beginning of the simulation. This element of the controller corrects a long-term bias, such as off-center steering wheel or constant wind. When Ki is small it helps the car move to the center of the road, overcoming its internal bias toward steering rightwards. But when Ki is too large, it destabilizes the trajectory. Since the sum of all errors accumulates quickly a large Ki will cause the effects of Kp and Kd to be overcome.

# Parameter tuning

To achieve smooth driving and fast reaction to turns, PID and PD parameters needed to be tuned. I did it manually through trial and error. 

PID controller moderates the steering angle. To find Kp, I started with a very small value of 0.001 and increased it until the car couldn't stay in the straight lane. Then I gradually increased Kd until the swerving was partially corrected. I started with a value of 0.1 for Ki, but that made the car's trajectory unstable. I gradually decreased it until it's effects were no longer destabilizing and settled at 0.001. The sum of error is set to zero when error is small to avoid the accumulation of error over time in the sum. After these modifications my filter was able to clear the first turn which is milder.

To be able to clear the sharper turns I increased the Kp and when the cars movements became more sinusoidal I also increaced Kd. Eventually I found a combination theat worked on all turns but one. The steering PID values are set at [0.1, 0.001, 1.2].

To clear that turn and to help smoothe out the car trajectory, I implemented a PD controller. The throttle is reduced when the error is large and when the change of error is positive (it is increasing) and it is increased when the change of error is negative (it is decreasing). I set the values for Kp and Kd at 0.05 and increased them until the driving was satisfactory and the sharp turn was cleared, finally settling for PD values of [0.15, 0.15.]
# PID-control
