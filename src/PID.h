#ifndef PID_H
#define PID_H

#include <math.h>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double Kp_th;
  double Kd_th;
  double sum_cte;
  double prev_cte;
  double d_cte;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, double Kp_th, double Kd_th);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  void TotalError(double cte);
  double ControlSignalSteer(double cte);
  double ControlSignalThrottle(double cte);
};

#endif /* PID_H */
