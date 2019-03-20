#include "PID.h"
#include <vector>
using std::vector;
#include <cmath>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
    p_error=0;
    i_error=0;
    d_error=0;
    Kp=Kp_;
    Ki=Ki_;
    Kd=Kd_;
    time_step=0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
    //vector<double> cte_total;
    //double pre_cte;
    //cte_total.push_back(cte);
    //p_error=cte;
    //i_error+=cte;
    //pre_cte=cte_total[cte_total.size()-1];
    //d_error=cte-pre_cte;
    double pre_cte;
    if(time_step==0){
        pre_cte=0;
    }
    else{
        pre_cte=p_error;
    }
    
    p_error=cte;
    i_error+=cte;
    if(cte==0){
        i_error=0;
    }
    
    d_error=cte-pre_cte;
    time_step+=1;
    
}

double PID::Output_pid() {
  return -Kp*p_error-Ki*i_error-Kd*d_error;
}
