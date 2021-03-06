#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <string>
#include <vector>
#include <map>

#include "ros/ros.h"

#include "route_description/OntologyManipulator.h"
#include "route_description/Routes.h"

class PathFinder
{
public:
  PathFinder(ros::NodeHandle* n);
  ~PathFinder() {}

  void find(std::string from_place, std::string to_place, std::string personnas, bool signpost = false);
  void find(std::string from_place, std::string to_place);
  void findDirections(std::string from_place, std::string to_place, std::string personnas, bool signpost = false);
  void findDirections(std::string from_place, std::string to_place);
  void findRegions(std::string from_place, std::string to_place, std::string personnas, bool signpost = false);
  void findRegions(std::string from_place, std::string to_place);
  routes_t getRoutes() {return completed_routes_; }
  std::vector<float> getCosts() {return costs_; }

private:
  ros::NodeHandle* n_;
  OntologyManipulator onto_;

  std::vector<std::string> from_region_;
  std::vector<std::string> to_region_;
  std::string personnas_;
  std::vector<routes_t> routes_;
  std::map<std::string, routes_t> place2place_;

  routes_t completed_routes_;
  std::vector<float> costs_;

  void init();
  void to_regions(std::string from_place, std::string to_place);
  void getRegionRoutes();
  void appendFromAndTo(std::string from_place, std::string to_place);
  void createPlace2Place();
  void getCompleteRoutes();
  void appendDirection();
  void printFinalRoutes();
  void computeCost();

  bool testToPlace(std::string to_place);
  std::string toPlace(std::string name);
};

#endif
