#ifndef PARAMETERS_H
#define PARAMETERS_H

Parameter inSource = {
        .type = TYPE_STRING,
        .iValue = 0,
        .sValue[0] = "Gen",
        .sValue[1] = "Analog",
        .sValue[2] = "Opto",
        .min = 0,
        .max = 2,
        .step = 1,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 0,
        .index = 0
};

Parameter inSourceFreq = {
        .type = TYPE_INTEGER,
        .iValue = 10000,
        .min = 0,
        .max = 100000,
        .step = 1,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 0,
        .index = 1
};

Parameter genFreq = {
        .type = TYPE_INTEGER,
        .iValue = 2,
        .min = 0,
        .max = 100000,
        .step = 1,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 0,
        .index = 1
};

Parameter channal1Devider = {
        .type = TYPE_INTEGER,
        .iValue = 3,
        .min = 0,
        .max = 65000,
        .step = 1,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 1,
        .index = 0
};

Parameter channal1Impulse = {
        .type = TYPE_INTEGER,
        .iValue = 4,
        .min = 0,
        .max = 65000,
        .step = 500,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 1,
        .index = 1
};

Parameter channal1Delay = {
        .type = TYPE_INTEGER,
        .iValue = 5,
        .min = 0,
        .max = 100000,
        .step = 500,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 1,
        .index = 2
};

Parameter channal2Devider = {
        .type = TYPE_INTEGER,
        .iValue = 3,
        .min = 0,
        .max = 65000,
        .step = 1,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 1,
        .index = 0
};

Parameter channal2Impulse = {
        .type = TYPE_INTEGER,
        .iValue = 4,
        .min = 0,
        .max = 65000,
        .step = 500,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 1,
        .index = 1
};

Parameter channal2Delay = {
        .type = TYPE_INTEGER,
        .iValue = 5,
        .min = 0,
        .max = 100000,
        .step = 500,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = 1,
        .index = 2
};

Parameter vddInt = {
        .type = TYPE_INTEGER,
        .iValue = 0,
        .min = 0,
        .max = 0,
        .step = 0,
        .mul1 = 0,
        .mul1Level = 0,
        .mul2 = 0,
        .mul2Level = 0,
        .adr = -1,
        .index = -1
};

Parameter tInt = {
        .type = TYPE_INTEGER,
        .iValue = 0,
        .min = 0,
        .max = 0,
        .step = 0,
        .mul1 = 0,
        .mul1Level = 0,
        .mul2 = 0,
        .mul2Level = 0,
        .adr = -1,
        .index = -1
};

Parameter lcdContast = {
        .type = TYPE_INTEGER,
        .iValue = 100,
        .min = 0,
        .max = 100,
        .step = 1,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = -1,
        .index = -1
};

Parameter saveAll = {
        .type = TYPE_STRING,
        .iValue = 0,
        .sValue[0] = "N",
        .sValue[1] = "Y",
        .min = 0,
        .max = 1,
        .step = 1,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = -1,
        .index = -1
};

Parameter loadAll = {
        .type = TYPE_STRING,
        .iValue = 0,
        .sValue[0] = "N",
        .sValue[1] = "Y",
        .min = 0,
        .max = 1,
        .step = 1,
        .mul1 = 1,
        .mul1Level = 1,
        .mul2 = 1,
        .mul2Level = 1,
        .adr = -1,
        .index = -1
};
#endif
