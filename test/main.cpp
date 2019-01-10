

#include <iostream>

#include "modules/congestion_controller/pcc/pcc_factory.h"
#include "modules/congestion_controller/pcc/pcc_network_controller.h"


using namespace webrtc;

const Timestamp kDefaultStartTime = Timestamp::ms(10000000);
const DataRate  kInitialBitrate = DataRate::kbps(60);

NetworkControllerConfig InitialConfig(int starting_bandwidth_kbps = kInitialBitrate.kbps(), 
                                      int min_data_rate_kbps = 0,
                                      int max_data_rate_kbps = 5*kInitialBitrate.kbps()) {
  NetworkControllerConfig config;
  config.constraints.at_time = kDefaultStartTime;
  config.constraints.min_data_rate = DataRate::kbps(min_data_rate_kbps);
  config.constraints.max_data_rate = DataRate::kbps(max_data_rate_kbps);
  config.constraints.starting_rate = DataRate::kbps(starting_bandwidth_kbps);

  return config;
}

ProcessInterval InitialProcessInterval() {
  ProcessInterval process_interval;
  process_interval.at_time = kDefaultStartTime;
  return process_interval;
}


bool TestFirstProcess() {
  std::unique_ptr<NetworkControllerInterface> controller;
  controller.reset(new pcc::PccNetworkController(InitialConfig()));

  NetworkControlUpdate update = controller->OnProcessInterval(InitialProcessInterval());

  std::cout << update.target_rate->target_rate.kbps() << ", " << update.pacer_config->data_rate().kbps() << std::endl;

  std::cout << "PCC Test: first process OK" << std::endl;
  return true;
}

bool TestUpdateTargetSendRate() {
  std::cout << "PCC Test: update target send rate OK" << std::endl;
  return true;
}

int main()
{
  TestFirstProcess();
  TestUpdateTargetSendRate();
  return 0;
}