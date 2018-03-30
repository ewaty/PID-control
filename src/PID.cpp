#include "PID.h"
using namespace std;


/*
* TODO: Complete the PID class.
*/

inline int sgn(double val) {
    return (0 < val) - (val < 0);
}

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double Kp_th, double Kd_th) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
	PID::Kp_th = Kp_th;
	PID::Kd_th = Kd_th;
	PID::sum_cte = 0;
	PID::prev_cte = 0;
	PID::d_cte = 0; 
}

void PID::UpdateError(double cte) {
	PID::d_cte = cte - PID::prev_cte;
	PID::prev_cte = cte;
}

void PID::TotalError(double cte) {
	PID::sum_cte += cte;
	if(cte < 0.001){
		PID::sum_cte = 0;
	}
}
double PID::ControlSignalSteer(double cte){
	return (- Kp*cte - Kd*d_cte - Ki*sum_cte);
}

double PID::ControlSignalThrottle(double cte){
	return (0.5 - Kp_th*fabs(cte) - Kd_th*d_cte*sgn(cte));
}


