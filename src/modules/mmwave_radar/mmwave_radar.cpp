#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <px4_platform_common/px4_work_queue/ScheduledWorkItem.hpp>
#include <uORB/Subscription.hpp>
#include <uORB/Publication.hpp>
#include <uORB/topics/vehicle_command.h>
#include <uORB/topics/vehicle_odometry.h>

using namespace time_literals;

class MmwaveRadar : public ModuleBase<MmwaveRadar>, public ModuleParams, public px4::ScheduledWorkItem
{
public:
    MmwaveRadar() : ModuleParams(nullptr), ScheduledWorkItem(MODULE_NAME, px4::wq_configurations::nav_and_controllers) {}
    ~MmwaveRadar() override = default;

    bool init() { ScheduleOnInterval(100_ms); return true; }

    void Run() override {
        if (should_exit()) { ScheduleClear(); exit_and_cleanup(); return; }
        if (_parameter_update_sub.updated()) { parameter_update_s p; _parameter_update_sub.copy(&p); updateParams(); }
        vehicle_command_s cmd; if (_cmd_sub.update(&cmd)) { vehicle_odometry_s odom{}; odom.timestamp = hrt_absolute_time(); _odom_pub.publish(odom); }
    }

    int print_status() override { PX4_INFO("running"); return 0; }

    static int task_spawn(int argc, char *argv[]) {
        MmwaveRadar *instance = new MmwaveRadar();
        if (instance) {
            _object.store(instance);
            _task_id = task_id_is_work_queue;
            if (instance->init()) { return PX4_OK; }
        }
        PX4_ERR("alloc failed");
        delete instance;
        return PX4_ERROR;
    }

    static int custom_command(int argc, char *argv[]) { return print_usage("unknown command"); }
    static int print_usage(const char *reason = nullptr) {
        if (reason) { PX4_WARN("%s", reason); }
        PRINT_MODULE_DESCRIPTION("Minimal mmwave_radar module");
        PRINT_MODULE_USAGE_NAME("mmwave_radar", "template");
        PRINT_MODULE_USAGE_COMMAND("start");
        PRINT_MODULE_USAGE_DEFAULT_COMMANDS();
        return 0;
    }

private:
    uORB::Subscription _parameter_update_sub{ORB_ID(parameter_update)};
    uORB::Subscription _cmd_sub{ORB_ID(vehicle_command)};
    uORB::Publication<vehicle_odometry_s> _odom_pub{ORB_ID(vehicle_odometry)};

    DEFINE_PARAMETERS(
        (ParamFloat<px4::params::NAV_ACC_RAD>) _param_dummy
    )
};

extern "C" __EXPORT int mmwave_radar_main(int argc, char *argv[])
{ return MmwaveRadar::main(argc, argv); }
