tlmServer.configData.tvmFileDir = "/users/dspray1/code/trick-tlm-server/sims/SIM_cannon_numeric/tvm_files"
tlmServer.configData.prototypeFileDir = "/users/dspray1/code/trick-tlm-server/sims/SIM_cannon_numeric/prototype_files"

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

tlmServer.configData.debugLoggingEnabled = True

# only set this to true if you want this to run as if it were just simulating
# a trick model producing/consuming data on SBN
tlmServer.configData.useSimulatedTrickBackend = True
