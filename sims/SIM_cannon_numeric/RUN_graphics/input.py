execfile("Modified_data/realtime.py")

#==========================================
# Start the Cannonball Graphics Client
#==========================================

CannonDisplay_path = "../models/graphics/dist/CannonDisplay.jar"

#==========================================
# Trick-SBN Config
#==========================================

tlmServer.configData.tvmFileDir = "/users/dspray1/code/tricksbn/sims/SIM_cannon_numeric/bittylicious_tvm_files"
tlmServer.configData.prototypeFileDir = "/users/dspray1/code/tricksbn/sims/SIM_cannon_numeric/bittylicious_ptype_files"

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

if (os.path.isfile(CannonDisplay_path)) :
    CannonDisplay_cmd = "java -jar " \
                   + CannonDisplay_path \
                   + " " + str(varServerPort) + " &" ;
    print(CannonDisplay_cmd)
    os.system( CannonDisplay_cmd);
else :
    print('==================================================================================')
    print('CannonDisplay needs to be built. Please \"cd\" into ../models/graphics and type \"make\".')
    print('==================================================================================')

