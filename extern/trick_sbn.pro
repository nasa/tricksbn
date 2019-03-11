TEMPLATE = subdirs

protobetter.file = protobetter/protobetter_dynamic.pro

SUBDIRS += \
    protobetter \
    trick_sbn_lib \
    trick_sbn_standalone \
    trick_sbn_test

CONFIG += ordered
