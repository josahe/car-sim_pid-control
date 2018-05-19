# Self-Driving Car Simulator - PID control
> PID controller implementation to drive the Udacity self-driving car simulator

## INTRODUCTION
The goal of this project is to write an implementation of the PID algorithm to control a car in simulation and successfully navigate one lap around the track without leaving the road. The PID algorithm is used to reduce cross-track error, calculated as the distance of the car from the centre of the lane.

A demonstration of the controller in action is show in this [video](project_video_output.mp4)

This project was undertaken as part of the [Udacity Self-Driving Car NanoDegree](https://eu.udacity.com/course/self-driving-car-engineer-nanodegree--nd013)

### Implementation reflection
#### Effects of P
The proportional term has the most directly attributable impact on the cross-track error. The larger the error, the larger the proportional term will be. Practically speaking, the further the car's distance from the centre, the larger the value that drives the steering angle in the opposite direction will be.
It is calculated by scaling the cross-track error proportionally to a gain parameter, `Kp`.
#### Effects of I
The integral term is slightly more nuanced than the proportional term, in that it continues to grow while the cross-track error is non-zero, and grows proportionally to the value of the error. This is supposed to have the effect of correcting any bias the car may have tracking the centre with a constant offset.
It is calculated by summing the cross-track errors over the previous 100 time steps and then scaling using gain parameter, `Ki`.
#### Effects of D
The derivative term reacts to rates of change in the cross-track error. The more quickly the car has steered away from the centre, the harder this term will act to correct it.
It is calculated by taking the difference between the current and previous cross-track errors and scaling using gain parameter, `Kd`
#### Choosing P
I started with only proportional action set to a vale of 1. I brought this value down manually and then made fine adjustments around 0.1 once I had introduced the other terms.
#### Choosing I
If set too high, integral action causes wild oscillations to build up that sends the car off-track. I considered removing the I term altogether but eventually used the gain to include a very small amount of integral action.
#### Choosing D
I introduced derivative action soon after reducing the proportional term to help the steering angle converge more quickly. I started with a value of 1, tried increasing which gave better results in some areas of the track but overall caused instability so eventually reduced back down until the car was stable.


## HOW TO USE
### Project dependencies
The original repository for this project has details for getting set up
* https://github.com/udacity/CarND-PID-Control-Project

## RELEVANT FILES
* [src/main.cpp](src/main.cpp)
  * Initialises the PID gain parameters and communicates with the simulator to receive cross-track error and send steering angle
* [src/pid.cpp](src/pid.cpp)
  * Init - Sets the gain parameters
  * UpdateError - Calculates each error term using the cross-track error
  * TotalError - Calculates the total error, in this case used to update the steering angle
