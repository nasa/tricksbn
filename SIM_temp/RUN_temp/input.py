trick.real_time_enable()
#trick.itimer_enable()
#trick.var_server_set_port(17000)

tricksbn.configData.tvmFileDir = "/users/jwpetti1/development/nexsys/tricksbn/demo2/apps/inc/tvm_files"
tricksbn.configData.prototypeFileDir = "/users/jwpetti1/development/nexsys/tricksbn/demo2/apps/inc/tvm_files"

tricksbn.configData.qsbnJsonConfig = '''

{
    "protocol":"stream",

    "timeout":3000,

    "sbnHostConfig":
    {
        "cpuId":2,
        "ip":"127.0.0.1",
        "port":15825
    },

    "sbnPeerConfig":
    [
        { "cpuId":1, "ip":"127.0.0.1", "port":15820 }
    ]
}

'''

# only set this to true if you want this to run as if it were just simulating
# a trick model producing/consuming data on SBN
tricksbn.configData.useSimulatedTrickBackend = False

tricksbn.io.debugEnabled = True