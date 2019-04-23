#trick.real_time_enable()
trick.frame_log_on()

tlmServer.configData.tvmFileDir = "bittylicious_tvm_files"
tlmServer.configData.prototypeFileDir = "bittylicious_ptype_files"

tlmServer.configData.qsbnJsonConfig = '''

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
        { "cpuId":1, "ip":"127.0.0.1", "port":15820 }
    ]
}

'''

# only set this to true if you want this to run as if it were just simulating
# a trick model producing/consuming data on SBN
tlmServer.configData.useSimulatedTrickBackend = False

tlmServer.stateData.debugEnabled = True 
