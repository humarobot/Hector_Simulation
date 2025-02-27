#ifndef PROJECT_BIPED_H
#define PROJECT_BIPED_H

#include "cppTypes.h"
#include "pinocchio/algorithm/frames.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include <iostream>
#include <ros/package.h>
#include <vector>
class Biped {
public:
  void setBiped() {

    mass = 13.856;

    leg_offset_x = 0.0;
    leg_offset_y = 0.047;   // 0.057;
    leg_offset_z = -0.1360; //-0.125;

    leg_offset_x2 = 0.0;
    leg_offset_y2 = 0.047; // 0.057;
    leg_offset_z2 = -0.136;

    hipLinkLength = 0.038; // hip offset in const.xacro
    thighLinkLength = 0.22;
    calfLinkLength = 0.22;
    std::string path = ros::package::getPath("hector_description");
    path += "/xacro/hector.urdf";
    pinocchio::urdf::buildModel(path, model_);
    data_ = pinocchio::Data(model_);
    q_.setZero(10);
  }
  int robot_index; // 1 for Aliengo, 2 for A1
  double hipLinkLength;
  double thighLinkLength;
  double calfLinkLength;
  double leg_offset_x;
  double leg_offset_y;
  double leg_offset_z;
  double leg_offset_x2;
  double leg_offset_y2;
  double leg_offset_z2;
  double mass;
  pinocchio::Model model_;
  pinocchio::Data data_;
  Eigen::VectorXd q_;
  Vec3<double> getHipLocation(int leg) {
    assert(leg >= 0 && leg < 2);
    Vec3<double> pHip = Vec3<double>::Zero();
    if (leg == 0) {
      pHip(0) = leg_offset_x;
      pHip(1) = leg_offset_y;
      pHip(2) = leg_offset_z;
    }
    if (leg == 1) {
      pHip(0) = leg_offset_x;
      pHip(1) = -leg_offset_y;
      pHip(2) = leg_offset_z;
    }
    return pHip;
  };

  Vec3<double> getHip2Location(int leg) {
    assert(leg >= 0 && leg < 2);
    Vec3<double> pHip2 = Vec3<double>::Zero();
    if (leg == 0) {
      pHip2(0) = leg_offset_x2;
      pHip2(1) = leg_offset_y2;
      pHip2(2) = leg_offset_z2;
    }
    if (leg == 1) {
      pHip2(0) = leg_offset_x2;
      pHip2(1) = -leg_offset_y2;
      pHip2(2) = leg_offset_z2;
    }
    return pHip2;
  };
};

#endif
