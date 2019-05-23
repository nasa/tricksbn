#trick.real_time_enable()
trick.frame_log_on()

tricksbn.configData.tvmFileDir = "bittylicious_tvm_files"
tricksbn.configData.prototypeFileDir = "bittylicious_ptype_files"

tricksbn.configData.qsbnJsonConfig = '''

{
    "protocol":"stream",

    "timeout":3000,

    "sbnHostConfig":
    {
        "cpuId":2,
        "ip":"127.0.0.1",
        "port":15821
    },

    "sbnPeerConfig":
    [
        { "cpuId":1, "ip":"127.0.0.1", "port":15820 },
        { "cpuId":3, "ip":"127.0.0.1", "port":15822 }
    ]
}

'''

# only set this to true if you want this to run as if it were just simulating
# a trick model producing/consuming data on SBN
tricksbn.configData.useSimulatedTrickBackend = False

tricksbn.io.debugEnabled = True 
