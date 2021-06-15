double PropsSI(const char *Output, const char *Name1, double Prop1, const char *Name2, double Prop2, const char *Ref);

double HAPropsSI(const char *Output, const char *Name1, double Prop1, const char *Name2, double Prop2, const char *Name3, double Prop3);

void *initializeCoolPropAbstractState(const char *backend, const char *fluidName);

void deleteCoolPropAbstractState(void *abstractState);

void updateCoolPropAbstractState(void *abstractState, double specificHeat, double pressure);

double keyedOutputCoolPropAbstractState(void *abstractState, const char *key);

#include <iostream>
#include <string>

int main() {
    const char *backend = "BICUBIC&HEOS"; // BICUBIC&HEOS // INCOMP
    const char *fluidName = "Water"; //"Water"; //"INCOMP::MPG"; // MPG
    void* abstractState = initializeCoolPropAbstractState(backend, fluidName);
    updateCoolPropAbstractState(abstractState, 100000.0, 100000.0);
    std::cout << keyedOutputCoolPropAbstractState(abstractState, "T") << std::endl;
    std::cout << keyedOutputCoolPropAbstractState(abstractState, "fake key");
    return 0;
}
