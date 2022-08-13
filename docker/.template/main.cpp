#include "youbot/YouBotBase.hpp"
#include "youbot/YouBotManipulator.hpp"
#include <iostream>
#include <math.h>

#define X_A1 0.15
#define D1 0.033
#define L1 0.075
#define L2 0.155
#define L3 0.135
#define L4 0.081
#define L5 0.137

// default youBot config installation dir
#define YOUBOT_CONFIGURATIONS_DIR "/usr/local/config/"

using namespace youbot;

YouBotBase *initYouBotBase();

YouBotManipulator *initYouBotManipulator();

int main()
{
    LOG(info) << "Program started";

    /* create handles for youBot base and manipulator (if available) */
    std::shared_ptr<YouBotBase> ybBase(initYouBotBase());
    std::shared_ptr<YouBotManipulator> ybArm(initYouBotManipulator());

    try
    {
        // if youBot base available
        if (ybBase)
        {
            // do something with base, e.g. move forward
        }

        // if youBot manipulator available
        if (ybArm)
        {
            // do something with manipulator, e.g. move joints
        }
    }
    catch (std::exception &e)
    {
        LOG(error) << "Unhandled exception: " << e.what();
    }

    LOG(info) << "Program completed";
    return 0;
}

YouBotBase *initYouBotBase()
{
    try
    {
        YouBotBase *ybBase = new YouBotBase("youbot-base", YOUBOT_CONFIGURATIONS_DIR);
        ybBase->doJointCommutation();
        return ybBase;
    }
    catch (std::exception &e)
    {
        LOG(warning) << "Unable to define robot base. " << e.what();
    }
    return nullptr;
}

YouBotManipulator *initYouBotManipulator()
{
    try
    {
        YouBotManipulator *ybArm = new YouBotManipulator("youbot-manipulator", YOUBOT_CONFIGURATIONS_DIR);
        ybArm->doJointCommutation();
        ybArm->calibrateManipulator();
        return ybArm;
    }
    catch (std::exception &e)
    {
        LOG(warning) << "Unable to define robot arm. " << e.what();
    }
    return nullptr;
}
