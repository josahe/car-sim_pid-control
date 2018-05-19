#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;

  for (auto& n : this->cte_history)
    n = 0;
}

void PID::UpdateError(double cte) {
  this->cte_history[this->i % this->size] = cte;

  // update P error term
  this->p_error = cte;

  // update I error term
  this->i_error = 0;
  for (auto& n : this->cte_history)
    this->i_error += n;

  // update D error term
  this->d_error = cte - this->cte_history[(this->i - 1) % this->size];

  ++this->i;
}

double PID::TotalError() {
  double P = (-this->Kp * this->p_error);
  double I = (-this->Kd * this->d_error);
  double D = (-this->Ki * this->i_error);
  return P + I + D;
}
