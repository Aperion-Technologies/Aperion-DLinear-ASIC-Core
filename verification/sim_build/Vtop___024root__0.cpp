// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ DLinearTop__DOT____Vcellinp__seasLayer__io_valid;
    DLinearTop__DOT____Vcellinp__seasLayer__io_valid = 0;
    // Body
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_0 
        = vlSelfRef.DLinearTop__DOT__trendWindow_0;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_1 
        = vlSelfRef.DLinearTop__DOT__trendWindow_1;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_2 
        = vlSelfRef.DLinearTop__DOT__trendWindow_2;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_3 
        = vlSelfRef.DLinearTop__DOT__trendWindow_3;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_4 
        = vlSelfRef.DLinearTop__DOT__trendWindow_4;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_5 
        = vlSelfRef.DLinearTop__DOT__trendWindow_5;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_6 
        = vlSelfRef.DLinearTop__DOT__trendWindow_6;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_7 
        = vlSelfRef.DLinearTop__DOT__trendWindow_7;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_8 
        = vlSelfRef.DLinearTop__DOT__trendWindow_8;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_9 
        = vlSelfRef.DLinearTop__DOT__trendWindow_9;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_10 
        = vlSelfRef.DLinearTop__DOT__trendWindow_10;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_11 
        = vlSelfRef.DLinearTop__DOT__trendWindow_11;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_12 
        = vlSelfRef.DLinearTop__DOT__trendWindow_12;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_13 
        = vlSelfRef.DLinearTop__DOT__trendWindow_13;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_14 
        = vlSelfRef.DLinearTop__DOT__trendWindow_14;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_15 
        = vlSelfRef.DLinearTop__DOT__trendWindow_15;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_16 
        = vlSelfRef.DLinearTop__DOT__trendWindow_16;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_17 
        = vlSelfRef.DLinearTop__DOT__trendWindow_17;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_18 
        = vlSelfRef.DLinearTop__DOT__trendWindow_18;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_19 
        = vlSelfRef.DLinearTop__DOT__trendWindow_19;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_20 
        = vlSelfRef.DLinearTop__DOT__trendWindow_20;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_21 
        = vlSelfRef.DLinearTop__DOT__trendWindow_21;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_22 
        = vlSelfRef.DLinearTop__DOT__trendWindow_22;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_23 
        = vlSelfRef.DLinearTop__DOT__trendWindow_23;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_24 
        = vlSelfRef.DLinearTop__DOT__trendWindow_24;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_25 
        = vlSelfRef.DLinearTop__DOT__trendWindow_25;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_26 
        = vlSelfRef.DLinearTop__DOT__trendWindow_26;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_27 
        = vlSelfRef.DLinearTop__DOT__trendWindow_27;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_28 
        = vlSelfRef.DLinearTop__DOT__trendWindow_28;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_29 
        = vlSelfRef.DLinearTop__DOT__trendWindow_29;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_30 
        = vlSelfRef.DLinearTop__DOT__trendWindow_30;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_31 
        = vlSelfRef.DLinearTop__DOT__trendWindow_31;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_32 
        = vlSelfRef.DLinearTop__DOT__trendWindow_32;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_33 
        = vlSelfRef.DLinearTop__DOT__trendWindow_33;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_34 
        = vlSelfRef.DLinearTop__DOT__trendWindow_34;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_35 
        = vlSelfRef.DLinearTop__DOT__trendWindow_35;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_36 
        = vlSelfRef.DLinearTop__DOT__trendWindow_36;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_37 
        = vlSelfRef.DLinearTop__DOT__trendWindow_37;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_38 
        = vlSelfRef.DLinearTop__DOT__trendWindow_38;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_39 
        = vlSelfRef.DLinearTop__DOT__trendWindow_39;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_40 
        = vlSelfRef.DLinearTop__DOT__trendWindow_40;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_41 
        = vlSelfRef.DLinearTop__DOT__trendWindow_41;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_42 
        = vlSelfRef.DLinearTop__DOT__trendWindow_42;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_43 
        = vlSelfRef.DLinearTop__DOT__trendWindow_43;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_44 
        = vlSelfRef.DLinearTop__DOT__trendWindow_44;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_45 
        = vlSelfRef.DLinearTop__DOT__trendWindow_45;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_46 
        = vlSelfRef.DLinearTop__DOT__trendWindow_46;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_47 
        = vlSelfRef.DLinearTop__DOT__trendWindow_47;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_48 
        = vlSelfRef.DLinearTop__DOT__trendWindow_48;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_49 
        = vlSelfRef.DLinearTop__DOT__trendWindow_49;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_50 
        = vlSelfRef.DLinearTop__DOT__trendWindow_50;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_51 
        = vlSelfRef.DLinearTop__DOT__trendWindow_51;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_52 
        = vlSelfRef.DLinearTop__DOT__trendWindow_52;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_53 
        = vlSelfRef.DLinearTop__DOT__trendWindow_53;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_54 
        = vlSelfRef.DLinearTop__DOT__trendWindow_54;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_55 
        = vlSelfRef.DLinearTop__DOT__trendWindow_55;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_56 
        = vlSelfRef.DLinearTop__DOT__trendWindow_56;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_57 
        = vlSelfRef.DLinearTop__DOT__trendWindow_57;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_58 
        = vlSelfRef.DLinearTop__DOT__trendWindow_58;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_59 
        = vlSelfRef.DLinearTop__DOT__trendWindow_59;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_60 
        = vlSelfRef.DLinearTop__DOT__trendWindow_60;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_61 
        = vlSelfRef.DLinearTop__DOT__trendWindow_61;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_62 
        = vlSelfRef.DLinearTop__DOT__trendWindow_62;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_63 
        = vlSelfRef.DLinearTop__DOT__trendWindow_63;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_0 
        = vlSelfRef.DLinearTop__DOT__seasWindow_0;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_1 
        = vlSelfRef.DLinearTop__DOT__seasWindow_1;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_2 
        = vlSelfRef.DLinearTop__DOT__seasWindow_2;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_3 
        = vlSelfRef.DLinearTop__DOT__seasWindow_3;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_4 
        = vlSelfRef.DLinearTop__DOT__seasWindow_4;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_5 
        = vlSelfRef.DLinearTop__DOT__seasWindow_5;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_6 
        = vlSelfRef.DLinearTop__DOT__seasWindow_6;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_7 
        = vlSelfRef.DLinearTop__DOT__seasWindow_7;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_8 
        = vlSelfRef.DLinearTop__DOT__seasWindow_8;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_9 
        = vlSelfRef.DLinearTop__DOT__seasWindow_9;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_10 
        = vlSelfRef.DLinearTop__DOT__seasWindow_10;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_11 
        = vlSelfRef.DLinearTop__DOT__seasWindow_11;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_12 
        = vlSelfRef.DLinearTop__DOT__seasWindow_12;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_13 
        = vlSelfRef.DLinearTop__DOT__seasWindow_13;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_14 
        = vlSelfRef.DLinearTop__DOT__seasWindow_14;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_15 
        = vlSelfRef.DLinearTop__DOT__seasWindow_15;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_16 
        = vlSelfRef.DLinearTop__DOT__seasWindow_16;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_17 
        = vlSelfRef.DLinearTop__DOT__seasWindow_17;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_18 
        = vlSelfRef.DLinearTop__DOT__seasWindow_18;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_19 
        = vlSelfRef.DLinearTop__DOT__seasWindow_19;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_20 
        = vlSelfRef.DLinearTop__DOT__seasWindow_20;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_21 
        = vlSelfRef.DLinearTop__DOT__seasWindow_21;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_22 
        = vlSelfRef.DLinearTop__DOT__seasWindow_22;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_23 
        = vlSelfRef.DLinearTop__DOT__seasWindow_23;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_24 
        = vlSelfRef.DLinearTop__DOT__seasWindow_24;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_25 
        = vlSelfRef.DLinearTop__DOT__seasWindow_25;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_26 
        = vlSelfRef.DLinearTop__DOT__seasWindow_26;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_27 
        = vlSelfRef.DLinearTop__DOT__seasWindow_27;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_28 
        = vlSelfRef.DLinearTop__DOT__seasWindow_28;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_29 
        = vlSelfRef.DLinearTop__DOT__seasWindow_29;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_30 
        = vlSelfRef.DLinearTop__DOT__seasWindow_30;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_31 
        = vlSelfRef.DLinearTop__DOT__seasWindow_31;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_32 
        = vlSelfRef.DLinearTop__DOT__seasWindow_32;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_33 
        = vlSelfRef.DLinearTop__DOT__seasWindow_33;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_34 
        = vlSelfRef.DLinearTop__DOT__seasWindow_34;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_35 
        = vlSelfRef.DLinearTop__DOT__seasWindow_35;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_36 
        = vlSelfRef.DLinearTop__DOT__seasWindow_36;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_37 
        = vlSelfRef.DLinearTop__DOT__seasWindow_37;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_38 
        = vlSelfRef.DLinearTop__DOT__seasWindow_38;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_39 
        = vlSelfRef.DLinearTop__DOT__seasWindow_39;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_40 
        = vlSelfRef.DLinearTop__DOT__seasWindow_40;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_41 
        = vlSelfRef.DLinearTop__DOT__seasWindow_41;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_42 
        = vlSelfRef.DLinearTop__DOT__seasWindow_42;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_43 
        = vlSelfRef.DLinearTop__DOT__seasWindow_43;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_44 
        = vlSelfRef.DLinearTop__DOT__seasWindow_44;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_45 
        = vlSelfRef.DLinearTop__DOT__seasWindow_45;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_46 
        = vlSelfRef.DLinearTop__DOT__seasWindow_46;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_47 
        = vlSelfRef.DLinearTop__DOT__seasWindow_47;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_48 
        = vlSelfRef.DLinearTop__DOT__seasWindow_48;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_49 
        = vlSelfRef.DLinearTop__DOT__seasWindow_49;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_50 
        = vlSelfRef.DLinearTop__DOT__seasWindow_50;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_51 
        = vlSelfRef.DLinearTop__DOT__seasWindow_51;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_52 
        = vlSelfRef.DLinearTop__DOT__seasWindow_52;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_53 
        = vlSelfRef.DLinearTop__DOT__seasWindow_53;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_54 
        = vlSelfRef.DLinearTop__DOT__seasWindow_54;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_55 
        = vlSelfRef.DLinearTop__DOT__seasWindow_55;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_56 
        = vlSelfRef.DLinearTop__DOT__seasWindow_56;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_57 
        = vlSelfRef.DLinearTop__DOT__seasWindow_57;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_58 
        = vlSelfRef.DLinearTop__DOT__seasWindow_58;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_59 
        = vlSelfRef.DLinearTop__DOT__seasWindow_59;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_60 
        = vlSelfRef.DLinearTop__DOT__seasWindow_60;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_61 
        = vlSelfRef.DLinearTop__DOT__seasWindow_61;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_62 
        = vlSelfRef.DLinearTop__DOT__seasWindow_62;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_63 
        = vlSelfRef.DLinearTop__DOT__seasWindow_63;
    vlSelfRef.DLinearTop__DOT__reset = vlSelfRef.reset;
    vlSelfRef.DLinearTop__DOT__decomp__DOT__io_trend 
        = (0x000000ffU & ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__runningSum) 
                          >> 6U));
    vlSelfRef.DLinearTop__DOT__io_status_weightsLoaded 
        = vlSelfRef.DLinearTop__DOT__weightsLoadedReg;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_result 
        = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_result_REG;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_resultValid 
        = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_resultValid_REG;
    vlSelfRef.DLinearTop__DOT__io_config_addr = vlSelfRef.io_config_addr;
    vlSelfRef.DLinearTop__DOT__io_config_data = vlSelfRef.io_config_data;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_result 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_result_REG;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_result 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_result_REG;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_resultValid 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_resultValid_REG;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_resultValid 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_resultValid_REG;
    vlSelfRef.DLinearTop__DOT__io_config_weightSel 
        = vlSelfRef.io_config_weightSel;
    vlSelfRef.DLinearTop__DOT__io_dataIn = vlSelfRef.io_dataIn;
    vlSelfRef.DLinearTop__DOT__clock = vlSelfRef.clock;
    vlSelfRef.DLinearTop__DOT__io_config_writeEn = vlSelfRef.io_config_writeEn;
    vlSelfRef.DLinearTop__DOT__io_dataValid = vlSelfRef.io_dataValid;
    vlSelfRef.DLinearTop__DOT__decomp__DOT__io_ready 
        = (1U & ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__fillCount) 
                 >> 6U));
    vlSelfRef.DLinearTop__DOT__io_configMode = vlSelfRef.io_configMode;
    vlSelfRef.DLinearTop__DOT__decomp__DOT__reset = vlSelfRef.DLinearTop__DOT__reset;
    vlSelfRef.DLinearTop__DOT___decomp_io_trend = vlSelfRef.DLinearTop__DOT__decomp__DOT__io_trend;
    vlSelfRef.io_status_weightsLoaded = vlSelfRef.DLinearTop__DOT__io_status_weightsLoaded;
    vlSelfRef.DLinearTop__DOT__io_predOut = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_result;
    vlSelfRef.DLinearTop__DOT__io_predValid = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_resultValid;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr 
        = vlSelfRef.DLinearTop__DOT__io_config_addr;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr 
        = vlSelfRef.DLinearTop__DOT__io_config_addr;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData 
        = vlSelfRef.DLinearTop__DOT__io_config_data;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData 
        = vlSelfRef.DLinearTop__DOT__io_config_data;
    vlSelfRef.DLinearTop__DOT___trendLayer_io_result 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_result;
    vlSelfRef.DLinearTop__DOT___seasLayer_io_result 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_result;
    vlSelfRef.DLinearTop__DOT___seasLayer_io_resultValid 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_resultValid;
    vlSelfRef.DLinearTop__DOT___trendLayer_io_resultValid 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_resultValid;
    vlSelfRef.DLinearTop__DOT__decomp__DOT__io_in = vlSelfRef.DLinearTop__DOT__io_dataIn;
    vlSelfRef.DLinearTop__DOT__decomp__DOT__clock = vlSelfRef.DLinearTop__DOT__clock;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__clock 
        = vlSelfRef.DLinearTop__DOT__clock;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__clock 
        = vlSelfRef.DLinearTop__DOT__clock;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__clock 
        = vlSelfRef.DLinearTop__DOT__clock;
    vlSelfRef.DLinearTop__DOT___decomp_io_ready = vlSelfRef.DLinearTop__DOT__decomp__DOT__io_ready;
    vlSelfRef.DLinearTop__DOT___seasLayer_io_weightEn_T 
        = ((IData)(vlSelfRef.DLinearTop__DOT__io_configMode) 
           & (IData)(vlSelfRef.DLinearTop__DOT__io_config_writeEn));
    vlSelfRef.DLinearTop__DOT____Vcellinp__decomp__io_valid 
        = ((~ (IData)(vlSelfRef.DLinearTop__DOT__io_configMode)) 
           & (IData)(vlSelfRef.DLinearTop__DOT__io_dataValid));
    vlSelfRef.io_predOut = vlSelfRef.DLinearTop__DOT__io_predOut;
    vlSelfRef.io_predValid = vlSelfRef.DLinearTop__DOT__io_predValid;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_a 
        = vlSelfRef.DLinearTop__DOT___trendLayer_io_result;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_b 
        = vlSelfRef.DLinearTop__DOT___seasLayer_io_result;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_valid 
        = ((IData)(vlSelfRef.DLinearTop__DOT___seasLayer_io_resultValid) 
           & (IData)(vlSelfRef.DLinearTop__DOT___trendLayer_io_resultValid));
    vlSelfRef.DLinearTop__DOT__decomp__DOT__io_seasonal 
        = (0x000000ffU & ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__io_in) 
                          - ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__runningSum) 
                             >> 6U)));
    vlSelfRef.DLinearTop__DOT__io_status_ready = ((IData)(vlSelfRef.DLinearTop__DOT___decomp_io_ready) 
                                                  & ((IData)(vlSelfRef.DLinearTop__DOT__windowFillCount) 
                                                     >> 6U));
    vlSelfRef.DLinearTop__DOT___seasLayer_io_valid_T 
        = (((IData)(vlSelfRef.DLinearTop__DOT__windowFillCount) 
            >> 6U) & (IData)(vlSelfRef.DLinearTop__DOT___decomp_io_ready));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn 
        = ((~ (IData)(vlSelfRef.DLinearTop__DOT__io_config_weightSel)) 
           & (IData)(vlSelfRef.DLinearTop__DOT___seasLayer_io_weightEn_T));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn 
        = ((IData)(vlSelfRef.DLinearTop__DOT___seasLayer_io_weightEn_T) 
           & (IData)(vlSelfRef.DLinearTop__DOT__io_config_weightSel));
    vlSelfRef.DLinearTop__DOT__decomp__DOT__io_valid 
        = vlSelfRef.DLinearTop__DOT____Vcellinp__decomp__io_valid;
    vlSelfRef.DLinearTop__DOT___decomp_io_seasonal 
        = vlSelfRef.DLinearTop__DOT__decomp__DOT__io_seasonal;
    vlSelfRef.io_status_ready = vlSelfRef.DLinearTop__DOT__io_status_ready;
    DLinearTop__DOT____Vcellinp__seasLayer__io_valid 
        = ((IData)(vlSelfRef.DLinearTop__DOT___seasLayer_io_valid_T) 
           & (IData)(vlSelfRef.DLinearTop__DOT____Vcellinp__decomp__io_valid));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_valid 
        = DLinearTop__DOT____Vcellinp__seasLayer__io_valid;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_valid 
        = DLinearTop__DOT____Vcellinp__seasLayer__io_valid;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__clock) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__fusionAdder__DOT__clock__0))) 
                                                      << 4U) 
                                                     | (((((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__clock) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__seasLayer__DOT__clock__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__clock) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__trendLayer__DOT__clock__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__clock) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__decomp__DOT__clock__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.DLinearTop__DOT__clock) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__clock__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__clock__0 
        = vlSelfRef.DLinearTop__DOT__clock;
    vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__decomp__DOT__clock__0 
        = vlSelfRef.DLinearTop__DOT__decomp__DOT__clock;
    vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__trendLayer__DOT__clock__0 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__clock;
    vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__seasLayer__DOT__clock__0 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__clock;
    vlSelfRef.__Vtrigprevexpr___TOP__DLinearTop__DOT__fusionAdder__DOT__clock__0 
        = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vdly__DLinearTop__DOT__windowFillCount;
    __Vdly__DLinearTop__DOT__windowFillCount = 0;
    // Body
    __Vdly__DLinearTop__DOT__windowFillCount = vlSelfRef.DLinearTop__DOT__windowFillCount;
    vlSelfRef.DLinearTop__DOT__weightsLoadedReg = (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.DLinearTop__DOT__reset))) 
                                                   && ((IData)(vlSelfRef.DLinearTop__DOT___seasLayer_io_weightEn_T) 
                                                       | (IData)(vlSelfRef.DLinearTop__DOT__weightsLoadedReg)));
    vlSelfRef.DLinearTop__DOT__unnamedblk1__DOT___GEN 
        = (((IData)(vlSelfRef.DLinearTop__DOT__io_dataValid) 
            & (~ (IData)(vlSelfRef.DLinearTop__DOT__io_configMode))) 
           & (IData)(vlSelfRef.DLinearTop__DOT___decomp_io_ready));
    if (vlSelfRef.DLinearTop__DOT__reset) {
        __Vdly__DLinearTop__DOT__windowFillCount = 0U;
    } else if (((IData)(vlSelfRef.DLinearTop__DOT__unnamedblk1__DOT___GEN) 
                & (~ ((IData)(vlSelfRef.DLinearTop__DOT__windowFillCount) 
                      >> 6U)))) {
        __Vdly__DLinearTop__DOT__windowFillCount = 
            (0x0000007fU & ((IData)(1U) + (IData)(vlSelfRef.DLinearTop__DOT__windowFillCount)));
    }
    if (vlSelfRef.DLinearTop__DOT__unnamedblk1__DOT___GEN) {
        vlSelfRef.DLinearTop__DOT__trendWindow_63 = vlSelfRef.DLinearTop__DOT__trendWindow_62;
        vlSelfRef.DLinearTop__DOT__seasWindow_63 = vlSelfRef.DLinearTop__DOT__seasWindow_62;
        vlSelfRef.DLinearTop__DOT__trendWindow_62 = vlSelfRef.DLinearTop__DOT__trendWindow_61;
        vlSelfRef.DLinearTop__DOT__seasWindow_62 = vlSelfRef.DLinearTop__DOT__seasWindow_61;
        vlSelfRef.DLinearTop__DOT__trendWindow_61 = vlSelfRef.DLinearTop__DOT__trendWindow_60;
        vlSelfRef.DLinearTop__DOT__seasWindow_61 = vlSelfRef.DLinearTop__DOT__seasWindow_60;
        vlSelfRef.DLinearTop__DOT__trendWindow_60 = vlSelfRef.DLinearTop__DOT__trendWindow_59;
        vlSelfRef.DLinearTop__DOT__seasWindow_60 = vlSelfRef.DLinearTop__DOT__seasWindow_59;
        vlSelfRef.DLinearTop__DOT__trendWindow_59 = vlSelfRef.DLinearTop__DOT__trendWindow_58;
        vlSelfRef.DLinearTop__DOT__seasWindow_59 = vlSelfRef.DLinearTop__DOT__seasWindow_58;
        vlSelfRef.DLinearTop__DOT__trendWindow_58 = vlSelfRef.DLinearTop__DOT__trendWindow_57;
        vlSelfRef.DLinearTop__DOT__seasWindow_58 = vlSelfRef.DLinearTop__DOT__seasWindow_57;
        vlSelfRef.DLinearTop__DOT__trendWindow_57 = vlSelfRef.DLinearTop__DOT__trendWindow_56;
        vlSelfRef.DLinearTop__DOT__seasWindow_57 = vlSelfRef.DLinearTop__DOT__seasWindow_56;
        vlSelfRef.DLinearTop__DOT__trendWindow_56 = vlSelfRef.DLinearTop__DOT__trendWindow_55;
        vlSelfRef.DLinearTop__DOT__seasWindow_56 = vlSelfRef.DLinearTop__DOT__seasWindow_55;
        vlSelfRef.DLinearTop__DOT__trendWindow_55 = vlSelfRef.DLinearTop__DOT__trendWindow_54;
        vlSelfRef.DLinearTop__DOT__seasWindow_55 = vlSelfRef.DLinearTop__DOT__seasWindow_54;
        vlSelfRef.DLinearTop__DOT__trendWindow_54 = vlSelfRef.DLinearTop__DOT__trendWindow_53;
        vlSelfRef.DLinearTop__DOT__seasWindow_54 = vlSelfRef.DLinearTop__DOT__seasWindow_53;
        vlSelfRef.DLinearTop__DOT__trendWindow_53 = vlSelfRef.DLinearTop__DOT__trendWindow_52;
        vlSelfRef.DLinearTop__DOT__seasWindow_53 = vlSelfRef.DLinearTop__DOT__seasWindow_52;
        vlSelfRef.DLinearTop__DOT__trendWindow_52 = vlSelfRef.DLinearTop__DOT__trendWindow_51;
        vlSelfRef.DLinearTop__DOT__seasWindow_52 = vlSelfRef.DLinearTop__DOT__seasWindow_51;
        vlSelfRef.DLinearTop__DOT__trendWindow_51 = vlSelfRef.DLinearTop__DOT__trendWindow_50;
        vlSelfRef.DLinearTop__DOT__seasWindow_51 = vlSelfRef.DLinearTop__DOT__seasWindow_50;
        vlSelfRef.DLinearTop__DOT__trendWindow_50 = vlSelfRef.DLinearTop__DOT__trendWindow_49;
        vlSelfRef.DLinearTop__DOT__seasWindow_50 = vlSelfRef.DLinearTop__DOT__seasWindow_49;
        vlSelfRef.DLinearTop__DOT__trendWindow_49 = vlSelfRef.DLinearTop__DOT__trendWindow_48;
        vlSelfRef.DLinearTop__DOT__seasWindow_49 = vlSelfRef.DLinearTop__DOT__seasWindow_48;
        vlSelfRef.DLinearTop__DOT__trendWindow_48 = vlSelfRef.DLinearTop__DOT__trendWindow_47;
        vlSelfRef.DLinearTop__DOT__seasWindow_48 = vlSelfRef.DLinearTop__DOT__seasWindow_47;
        vlSelfRef.DLinearTop__DOT__trendWindow_47 = vlSelfRef.DLinearTop__DOT__trendWindow_46;
        vlSelfRef.DLinearTop__DOT__seasWindow_47 = vlSelfRef.DLinearTop__DOT__seasWindow_46;
        vlSelfRef.DLinearTop__DOT__trendWindow_46 = vlSelfRef.DLinearTop__DOT__trendWindow_45;
        vlSelfRef.DLinearTop__DOT__seasWindow_46 = vlSelfRef.DLinearTop__DOT__seasWindow_45;
        vlSelfRef.DLinearTop__DOT__trendWindow_45 = vlSelfRef.DLinearTop__DOT__trendWindow_44;
        vlSelfRef.DLinearTop__DOT__seasWindow_45 = vlSelfRef.DLinearTop__DOT__seasWindow_44;
        vlSelfRef.DLinearTop__DOT__trendWindow_44 = vlSelfRef.DLinearTop__DOT__trendWindow_43;
        vlSelfRef.DLinearTop__DOT__seasWindow_44 = vlSelfRef.DLinearTop__DOT__seasWindow_43;
        vlSelfRef.DLinearTop__DOT__trendWindow_43 = vlSelfRef.DLinearTop__DOT__trendWindow_42;
        vlSelfRef.DLinearTop__DOT__seasWindow_43 = vlSelfRef.DLinearTop__DOT__seasWindow_42;
        vlSelfRef.DLinearTop__DOT__trendWindow_42 = vlSelfRef.DLinearTop__DOT__trendWindow_41;
        vlSelfRef.DLinearTop__DOT__seasWindow_42 = vlSelfRef.DLinearTop__DOT__seasWindow_41;
        vlSelfRef.DLinearTop__DOT__trendWindow_41 = vlSelfRef.DLinearTop__DOT__trendWindow_40;
        vlSelfRef.DLinearTop__DOT__seasWindow_41 = vlSelfRef.DLinearTop__DOT__seasWindow_40;
        vlSelfRef.DLinearTop__DOT__trendWindow_40 = vlSelfRef.DLinearTop__DOT__trendWindow_39;
        vlSelfRef.DLinearTop__DOT__seasWindow_40 = vlSelfRef.DLinearTop__DOT__seasWindow_39;
        vlSelfRef.DLinearTop__DOT__trendWindow_39 = vlSelfRef.DLinearTop__DOT__trendWindow_38;
        vlSelfRef.DLinearTop__DOT__seasWindow_39 = vlSelfRef.DLinearTop__DOT__seasWindow_38;
        vlSelfRef.DLinearTop__DOT__trendWindow_38 = vlSelfRef.DLinearTop__DOT__trendWindow_37;
        vlSelfRef.DLinearTop__DOT__seasWindow_38 = vlSelfRef.DLinearTop__DOT__seasWindow_37;
        vlSelfRef.DLinearTop__DOT__trendWindow_37 = vlSelfRef.DLinearTop__DOT__trendWindow_36;
        vlSelfRef.DLinearTop__DOT__seasWindow_37 = vlSelfRef.DLinearTop__DOT__seasWindow_36;
        vlSelfRef.DLinearTop__DOT__trendWindow_36 = vlSelfRef.DLinearTop__DOT__trendWindow_35;
        vlSelfRef.DLinearTop__DOT__seasWindow_36 = vlSelfRef.DLinearTop__DOT__seasWindow_35;
        vlSelfRef.DLinearTop__DOT__trendWindow_35 = vlSelfRef.DLinearTop__DOT__trendWindow_34;
        vlSelfRef.DLinearTop__DOT__seasWindow_35 = vlSelfRef.DLinearTop__DOT__seasWindow_34;
        vlSelfRef.DLinearTop__DOT__trendWindow_34 = vlSelfRef.DLinearTop__DOT__trendWindow_33;
        vlSelfRef.DLinearTop__DOT__seasWindow_34 = vlSelfRef.DLinearTop__DOT__seasWindow_33;
        vlSelfRef.DLinearTop__DOT__trendWindow_33 = vlSelfRef.DLinearTop__DOT__trendWindow_32;
        vlSelfRef.DLinearTop__DOT__seasWindow_33 = vlSelfRef.DLinearTop__DOT__seasWindow_32;
        vlSelfRef.DLinearTop__DOT__trendWindow_32 = vlSelfRef.DLinearTop__DOT__trendWindow_31;
        vlSelfRef.DLinearTop__DOT__seasWindow_32 = vlSelfRef.DLinearTop__DOT__seasWindow_31;
        vlSelfRef.DLinearTop__DOT__trendWindow_31 = vlSelfRef.DLinearTop__DOT__trendWindow_30;
        vlSelfRef.DLinearTop__DOT__seasWindow_31 = vlSelfRef.DLinearTop__DOT__seasWindow_30;
        vlSelfRef.DLinearTop__DOT__trendWindow_30 = vlSelfRef.DLinearTop__DOT__trendWindow_29;
        vlSelfRef.DLinearTop__DOT__seasWindow_30 = vlSelfRef.DLinearTop__DOT__seasWindow_29;
        vlSelfRef.DLinearTop__DOT__trendWindow_29 = vlSelfRef.DLinearTop__DOT__trendWindow_28;
        vlSelfRef.DLinearTop__DOT__seasWindow_29 = vlSelfRef.DLinearTop__DOT__seasWindow_28;
        vlSelfRef.DLinearTop__DOT__trendWindow_28 = vlSelfRef.DLinearTop__DOT__trendWindow_27;
        vlSelfRef.DLinearTop__DOT__seasWindow_28 = vlSelfRef.DLinearTop__DOT__seasWindow_27;
        vlSelfRef.DLinearTop__DOT__trendWindow_27 = vlSelfRef.DLinearTop__DOT__trendWindow_26;
        vlSelfRef.DLinearTop__DOT__seasWindow_27 = vlSelfRef.DLinearTop__DOT__seasWindow_26;
        vlSelfRef.DLinearTop__DOT__trendWindow_26 = vlSelfRef.DLinearTop__DOT__trendWindow_25;
        vlSelfRef.DLinearTop__DOT__seasWindow_26 = vlSelfRef.DLinearTop__DOT__seasWindow_25;
        vlSelfRef.DLinearTop__DOT__trendWindow_25 = vlSelfRef.DLinearTop__DOT__trendWindow_24;
        vlSelfRef.DLinearTop__DOT__seasWindow_25 = vlSelfRef.DLinearTop__DOT__seasWindow_24;
        vlSelfRef.DLinearTop__DOT__trendWindow_24 = vlSelfRef.DLinearTop__DOT__trendWindow_23;
        vlSelfRef.DLinearTop__DOT__seasWindow_24 = vlSelfRef.DLinearTop__DOT__seasWindow_23;
        vlSelfRef.DLinearTop__DOT__trendWindow_23 = vlSelfRef.DLinearTop__DOT__trendWindow_22;
        vlSelfRef.DLinearTop__DOT__seasWindow_23 = vlSelfRef.DLinearTop__DOT__seasWindow_22;
        vlSelfRef.DLinearTop__DOT__trendWindow_22 = vlSelfRef.DLinearTop__DOT__trendWindow_21;
        vlSelfRef.DLinearTop__DOT__seasWindow_22 = vlSelfRef.DLinearTop__DOT__seasWindow_21;
        vlSelfRef.DLinearTop__DOT__trendWindow_21 = vlSelfRef.DLinearTop__DOT__trendWindow_20;
        vlSelfRef.DLinearTop__DOT__seasWindow_21 = vlSelfRef.DLinearTop__DOT__seasWindow_20;
        vlSelfRef.DLinearTop__DOT__trendWindow_20 = vlSelfRef.DLinearTop__DOT__trendWindow_19;
        vlSelfRef.DLinearTop__DOT__seasWindow_20 = vlSelfRef.DLinearTop__DOT__seasWindow_19;
        vlSelfRef.DLinearTop__DOT__trendWindow_19 = vlSelfRef.DLinearTop__DOT__trendWindow_18;
        vlSelfRef.DLinearTop__DOT__seasWindow_19 = vlSelfRef.DLinearTop__DOT__seasWindow_18;
        vlSelfRef.DLinearTop__DOT__trendWindow_18 = vlSelfRef.DLinearTop__DOT__trendWindow_17;
        vlSelfRef.DLinearTop__DOT__seasWindow_18 = vlSelfRef.DLinearTop__DOT__seasWindow_17;
        vlSelfRef.DLinearTop__DOT__trendWindow_17 = vlSelfRef.DLinearTop__DOT__trendWindow_16;
        vlSelfRef.DLinearTop__DOT__seasWindow_17 = vlSelfRef.DLinearTop__DOT__seasWindow_16;
        vlSelfRef.DLinearTop__DOT__trendWindow_16 = vlSelfRef.DLinearTop__DOT__trendWindow_15;
        vlSelfRef.DLinearTop__DOT__seasWindow_16 = vlSelfRef.DLinearTop__DOT__seasWindow_15;
        vlSelfRef.DLinearTop__DOT__trendWindow_15 = vlSelfRef.DLinearTop__DOT__trendWindow_14;
        vlSelfRef.DLinearTop__DOT__seasWindow_15 = vlSelfRef.DLinearTop__DOT__seasWindow_14;
        vlSelfRef.DLinearTop__DOT__trendWindow_14 = vlSelfRef.DLinearTop__DOT__trendWindow_13;
        vlSelfRef.DLinearTop__DOT__seasWindow_14 = vlSelfRef.DLinearTop__DOT__seasWindow_13;
        vlSelfRef.DLinearTop__DOT__trendWindow_13 = vlSelfRef.DLinearTop__DOT__trendWindow_12;
        vlSelfRef.DLinearTop__DOT__seasWindow_13 = vlSelfRef.DLinearTop__DOT__seasWindow_12;
        vlSelfRef.DLinearTop__DOT__trendWindow_12 = vlSelfRef.DLinearTop__DOT__trendWindow_11;
        vlSelfRef.DLinearTop__DOT__seasWindow_12 = vlSelfRef.DLinearTop__DOT__seasWindow_11;
        vlSelfRef.DLinearTop__DOT__trendWindow_11 = vlSelfRef.DLinearTop__DOT__trendWindow_10;
        vlSelfRef.DLinearTop__DOT__seasWindow_11 = vlSelfRef.DLinearTop__DOT__seasWindow_10;
        vlSelfRef.DLinearTop__DOT__trendWindow_10 = vlSelfRef.DLinearTop__DOT__trendWindow_9;
        vlSelfRef.DLinearTop__DOT__seasWindow_10 = vlSelfRef.DLinearTop__DOT__seasWindow_9;
        vlSelfRef.DLinearTop__DOT__trendWindow_9 = vlSelfRef.DLinearTop__DOT__trendWindow_8;
        vlSelfRef.DLinearTop__DOT__seasWindow_9 = vlSelfRef.DLinearTop__DOT__seasWindow_8;
        vlSelfRef.DLinearTop__DOT__trendWindow_8 = vlSelfRef.DLinearTop__DOT__trendWindow_7;
        vlSelfRef.DLinearTop__DOT__seasWindow_8 = vlSelfRef.DLinearTop__DOT__seasWindow_7;
        vlSelfRef.DLinearTop__DOT__trendWindow_7 = vlSelfRef.DLinearTop__DOT__trendWindow_6;
        vlSelfRef.DLinearTop__DOT__seasWindow_7 = vlSelfRef.DLinearTop__DOT__seasWindow_6;
        vlSelfRef.DLinearTop__DOT__trendWindow_6 = vlSelfRef.DLinearTop__DOT__trendWindow_5;
        vlSelfRef.DLinearTop__DOT__seasWindow_6 = vlSelfRef.DLinearTop__DOT__seasWindow_5;
        vlSelfRef.DLinearTop__DOT__trendWindow_5 = vlSelfRef.DLinearTop__DOT__trendWindow_4;
        vlSelfRef.DLinearTop__DOT__seasWindow_5 = vlSelfRef.DLinearTop__DOT__seasWindow_4;
        vlSelfRef.DLinearTop__DOT__trendWindow_4 = vlSelfRef.DLinearTop__DOT__trendWindow_3;
        vlSelfRef.DLinearTop__DOT__seasWindow_4 = vlSelfRef.DLinearTop__DOT__seasWindow_3;
        vlSelfRef.DLinearTop__DOT__trendWindow_3 = vlSelfRef.DLinearTop__DOT__trendWindow_2;
        vlSelfRef.DLinearTop__DOT__seasWindow_3 = vlSelfRef.DLinearTop__DOT__seasWindow_2;
        vlSelfRef.DLinearTop__DOT__trendWindow_2 = vlSelfRef.DLinearTop__DOT__trendWindow_1;
        vlSelfRef.DLinearTop__DOT__seasWindow_2 = vlSelfRef.DLinearTop__DOT__seasWindow_1;
        vlSelfRef.DLinearTop__DOT__trendWindow_1 = vlSelfRef.DLinearTop__DOT__trendWindow_0;
        vlSelfRef.DLinearTop__DOT__seasWindow_1 = vlSelfRef.DLinearTop__DOT__seasWindow_0;
        vlSelfRef.DLinearTop__DOT__trendWindow_0 = vlSelfRef.DLinearTop__DOT___decomp_io_trend;
        vlSelfRef.DLinearTop__DOT__seasWindow_0 = vlSelfRef.DLinearTop__DOT___decomp_io_seasonal;
    }
    vlSelfRef.DLinearTop__DOT__windowFillCount = __Vdly__DLinearTop__DOT__windowFillCount;
    vlSelfRef.DLinearTop__DOT__io_status_weightsLoaded 
        = vlSelfRef.DLinearTop__DOT__weightsLoadedReg;
    vlSelfRef.io_status_weightsLoaded = vlSelfRef.DLinearTop__DOT__io_status_weightsLoaded;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vdly__DLinearTop__DOT__decomp__DOT__fillCount;
    __Vdly__DLinearTop__DOT__decomp__DOT__fillCount = 0;
    SData/*13:0*/ __Vdly__DLinearTop__DOT__decomp__DOT__runningSum;
    __Vdly__DLinearTop__DOT__decomp__DOT__runningSum = 0;
    // Body
    __Vdly__DLinearTop__DOT__decomp__DOT__runningSum 
        = vlSelfRef.DLinearTop__DOT__decomp__DOT__runningSum;
    __Vdly__DLinearTop__DOT__decomp__DOT__fillCount 
        = vlSelfRef.DLinearTop__DOT__decomp__DOT__fillCount;
    if (vlSelfRef.DLinearTop__DOT__decomp__DOT__reset) {
        __Vdly__DLinearTop__DOT__decomp__DOT__fillCount = 0U;
        __Vdly__DLinearTop__DOT__decomp__DOT__runningSum = 0U;
    } else {
        if ((1U & (~ ((~ (IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__io_valid)) 
                      | ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__fillCount) 
                         >> 6U))))) {
            __Vdly__DLinearTop__DOT__decomp__DOT__fillCount 
                = (0x0000007fU & ((IData)(1U) + (IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__fillCount)));
        }
        if (vlSelfRef.DLinearTop__DOT__decomp__DOT__io_valid) {
            vlSelfRef.DLinearTop__DOT__decomp__DOT__unnamedblk1__DOT___GEN 
                = ((0x00003f00U & ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__io_in) 
                                                >> 7U)))) 
                                   << 8U)) | (IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__io_in));
            __Vdly__DLinearTop__DOT__decomp__DOT__runningSum 
                = (0x00003fffU & ((0x00000040U & (IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__fillCount))
                                   ? (((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__runningSum) 
                                       + (IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__unnamedblk1__DOT___GEN)) 
                                      - ((0x00003f00U 
                                          & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_63) 
                                                            >> 7U)))) 
                                             << 8U)) 
                                         | (IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_63)))
                                   : ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__runningSum) 
                                      + (IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__unnamedblk1__DOT___GEN))));
        }
    }
    vlSelfRef.DLinearTop__DOT__decomp__DOT__runningSum 
        = __Vdly__DLinearTop__DOT__decomp__DOT__runningSum;
    vlSelfRef.DLinearTop__DOT__decomp__DOT__fillCount 
        = __Vdly__DLinearTop__DOT__decomp__DOT__fillCount;
    vlSelfRef.DLinearTop__DOT__decomp__DOT__io_trend 
        = (0x000000ffU & ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__runningSum) 
                          >> 6U));
    vlSelfRef.DLinearTop__DOT__decomp__DOT__io_seasonal 
        = (0x000000ffU & ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__io_in) 
                          - ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__runningSum) 
                             >> 6U)));
    vlSelfRef.DLinearTop__DOT__decomp__DOT__io_ready 
        = (1U & ((IData)(vlSelfRef.DLinearTop__DOT__decomp__DOT__fillCount) 
                 >> 6U));
    if (vlSelfRef.DLinearTop__DOT__decomp__DOT__io_valid) {
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_63 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_62;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_62 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_61;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_61 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_60;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_60 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_59;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_59 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_58;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_58 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_57;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_57 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_56;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_56 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_55;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_55 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_54;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_54 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_53;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_53 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_52;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_52 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_51;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_51 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_50;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_50 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_49;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_49 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_48;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_48 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_47;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_47 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_46;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_46 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_45;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_45 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_44;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_44 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_43;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_43 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_42;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_42 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_41;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_41 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_40;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_40 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_39;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_39 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_38;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_38 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_37;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_37 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_36;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_36 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_35;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_35 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_34;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_34 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_33;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_33 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_32;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_32 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_31;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_31 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_30;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_30 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_29;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_29 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_28;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_28 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_27;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_27 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_26;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_26 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_25;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_25 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_24;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_24 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_23;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_23 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_22;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_22 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_21;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_21 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_20;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_20 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_19;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_19 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_18;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_18 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_17;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_17 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_16;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_16 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_15;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_15 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_14;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_14 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_13;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_13 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_12;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_12 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_11;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_11 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_10;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_10 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_9;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_9 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_8;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_8 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_7;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_7 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_6;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_6 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_5;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_5 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_4;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_4 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_3;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_3 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_2;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_2 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_1;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_1 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_0;
        vlSelfRef.DLinearTop__DOT__decomp__DOT__shiftReg_0 
            = vlSelfRef.DLinearTop__DOT__decomp__DOT__io_in;
    }
    vlSelfRef.DLinearTop__DOT___decomp_io_trend = vlSelfRef.DLinearTop__DOT__decomp__DOT__io_trend;
    vlSelfRef.DLinearTop__DOT___decomp_io_seasonal 
        = vlSelfRef.DLinearTop__DOT__decomp__DOT__io_seasonal;
    vlSelfRef.DLinearTop__DOT___decomp_io_ready = vlSelfRef.DLinearTop__DOT__decomp__DOT__io_ready;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_resultValid_REG 
        = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_valid;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__unnamedblk1__DOT__sum 
        = (0x01ffffffU & (((0x01000000U & (vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_b 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_b) 
                          + ((0x01000000U & (vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_a 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_a)));
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_result_REG 
        = (VL_LTS_III(25, 0x007fffffU, vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__unnamedblk1__DOT__sum)
            ? 0x007fffffU : (VL_GTS_III(25, 0x01800000U, vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__unnamedblk1__DOT__sum)
                              ? 0x00800000U : (0x00ffffffU 
                                               & vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__unnamedblk1__DOT__sum)));
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_resultValid 
        = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_resultValid_REG;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_result 
        = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_result_REG;
    vlSelfRef.DLinearTop__DOT__io_predValid = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_resultValid;
    vlSelfRef.DLinearTop__DOT__io_predOut = vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_result;
    vlSelfRef.io_predValid = vlSelfRef.DLinearTop__DOT__io_predValid;
    vlSelfRef.io_predOut = vlSelfRef.DLinearTop__DOT__io_predOut;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_resultValid_REG 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage3_valid;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_31 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_1 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_1) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_0 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_0)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_32 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_3 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_3) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_2 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_2)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_33 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_5 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_5) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_4 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_4)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_34 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_7 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_7) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_6 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_6)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_35 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_9 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_9) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_8 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_8)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_36 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_11 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_11) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_10 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_10)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_37 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_13 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_13) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_12 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_12)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_38 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_15 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_15) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_14 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_14)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_39 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_17 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_17) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_16 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_16)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_40 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_19 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_19) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_18 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_18)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_41 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_21 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_21) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_20 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_20)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_42 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_23 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_23) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_22 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_22)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_43 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_25 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_25) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_24 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_24)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_44 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_27 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_27) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_26 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_26)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_45 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_29 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_29) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_28 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_28)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_46 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_31 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_31) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_30 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_30)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_result_REG 
        = (0x00ffffffU & (((((((((((((((((0x00800000U 
                                          & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_31 
                                             << 1U)) 
                                         | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_31) 
                                        + ((0x00800000U 
                                            & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_32 
                                               << 1U)) 
                                           | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_32)) 
                                       + ((0x00800000U 
                                           & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_33 
                                              << 1U)) 
                                          | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_33)) 
                                      + ((0x00800000U 
                                          & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_34 
                                             << 1U)) 
                                         | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_34)) 
                                     + ((0x00800000U 
                                         & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_35 
                                            << 1U)) 
                                        | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_35)) 
                                    + ((0x00800000U 
                                        & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_36 
                                           << 1U)) 
                                       | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_36)) 
                                   + ((0x00800000U 
                                       & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_37 
                                          << 1U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_37)) 
                                  + ((0x00800000U & 
                                      (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_38 
                                       << 1U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_38)) 
                                 + ((0x00800000U & 
                                     (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_39 
                                      << 1U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_39)) 
                                + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_40 
                                                   << 1U)) 
                                   | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_40)) 
                               + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_41 
                                                  << 1U)) 
                                  | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_41)) 
                              + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_42 
                                                 << 1U)) 
                                 | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_42)) 
                             + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_43 
                                                << 1U)) 
                                | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_43)) 
                            + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_44 
                                               << 1U)) 
                               | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_44)) 
                           + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_45 
                                              << 1U)) 
                              | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_45)) 
                          + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_46 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_46)));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_resultValid 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_resultValid_REG;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage3_valid 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_valid;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_result 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_result_REG;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_0 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_3) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_3)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_2) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_2))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_1 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_0 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_0);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_1) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_1)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_0) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_0))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_0 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_2 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_7) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_7)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_6) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_6))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_3 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_2 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_2);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_1 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_5) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_5)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_4) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_4))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_2 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_1 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_1);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_4 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_11) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_11)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_10) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_10))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_5 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_4 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_4);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_3 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_9) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_9)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_8) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_8))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_4 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_3 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_3);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_6 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_15) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_15)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_14) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_14))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_7 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_6 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_6);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_5 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_13) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_13)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_12) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_12))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_6 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_5 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_5);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_8 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_19) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_19)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_18) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_18))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_9 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_8 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_8);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_7 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_17) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_17)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_16) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_16))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_8 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_7 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_7);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_10 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_23) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_23)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_22) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_22))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_11 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_10 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_10);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_9 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_21) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_21)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_20) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_20))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_10 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_9 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_9);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_12 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_27) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_27)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_26) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_26))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_13 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_12 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_12);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_11 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_25) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_25)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_24) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_24))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_12 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_11 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_11);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_14 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_31) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_31)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_30) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_30))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_15 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_14 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_14);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_13 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_29) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_29)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_28) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_28))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_14 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_13 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_13);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_16 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_35) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_35)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_34) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_34))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_17 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_16 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_16);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_15 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_33) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_33)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_32) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_32))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_16 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_15 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_15);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_18 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_39) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_39)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_38) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_38))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_19 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_18 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_18);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_17 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_37) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_37)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_36) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_36))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_18 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_17 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_17);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_20 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_43) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_43)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_42) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_42))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_21 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_20 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_20);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_19 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_41) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_41)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_40) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_40))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_20 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_19 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_19);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_22 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_47) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_47)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_46) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_46))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_23 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_22 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_22);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_21 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_45) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_45)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_44) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_44))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_22 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_21 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_21);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_24 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_51) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_51)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_50) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_50))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_25 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_24 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_24);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_23 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_49) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_49)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_48) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_48))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_24 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_23 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_23);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_26 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_55) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_55)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_54) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_54))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_27 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_26 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_26);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_25 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_53) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_53)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_52) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_52))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_26 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_25 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_25);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_28 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_59) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_59)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_58) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_58))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_29 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_28 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_28);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_27 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_57) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_57)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_56) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_56))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_28 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_27 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_27);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_30 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_63) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_63)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_62) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_62))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_31 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_30 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_30);
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_29 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_61) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_61)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_60) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_60))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_sums_30 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_29 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_29);
    vlSelfRef.DLinearTop__DOT___trendLayer_io_resultValid 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_resultValid;
    vlSelfRef.DLinearTop__DOT___trendLayer_io_result 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_result;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage2_valid 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_valid;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_a 
        = vlSelfRef.DLinearTop__DOT___trendLayer_io_result;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_3 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_3) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_3)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_3) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_3))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_2 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_2) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_2)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_2) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_2))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_1 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_1) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_1)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_1) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_1))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_0 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_0) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_0)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_0) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_0))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_7 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_7) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_7)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_7) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_7))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_6 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_6) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_6)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_6) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_6))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_5 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_5) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_5)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_5) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_5))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_4 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_4) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_4)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_4) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_4))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_11 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_11) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_11)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_11) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_11))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_10 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_10) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_10)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_10) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_10))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_9 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_9) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_9)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_9) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_9))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_8 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_8) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_8)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_8) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_8))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_15 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_15) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_15)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_15) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_15))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_14 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_14) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_14)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_14) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_14))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_13 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_13) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_13)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_13) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_13))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_12 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_12) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_12)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_12) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_12))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_19 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_19) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_19)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_19) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_19))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_18 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_18) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_18)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_18) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_18))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_17 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_17) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_17)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_17) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_17))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_16 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_16) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_16)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_16) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_16))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_23 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_23) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_23)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_23) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_23))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_22 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_22) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_22)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_22) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_22))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_21 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_21) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_21)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_21) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_21))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_20 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_20) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_20)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_20) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_20))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_27 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_27) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_27)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_27) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_27))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_26 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_26) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_26)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_26) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_26))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_25 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_25) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_25)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_25) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_25))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_24 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_24) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_24)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_24) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_24))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_31 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_31) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_31)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_31) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_31))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_30 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_30) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_30)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_30) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_30))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_29 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_29) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_29)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_29) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_29))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_28 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_28) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_28)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_28) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_28))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_35 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_35) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_35)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_35) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_35))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_34 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_34) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_34)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_34) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_34))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_33 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_33) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_33)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_33) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_33))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_32 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_32) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_32)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_32) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_32))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_39 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_39) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_39)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_39) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_39))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_38 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_38) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_38)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_38) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_38))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_37 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_37) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_37)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_37) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_37))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_36 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_36) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_36)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_36) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_36))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_43 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_43) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_43)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_43) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_43))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_42 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_42) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_42)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_42) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_42))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_41 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_41) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_41)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_41) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_41))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_40 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_40) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_40)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_40) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_40))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_47 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_47) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_47)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_47) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_47))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_46 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_46) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_46)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_46) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_46))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_45 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_45) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_45)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_45) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_45))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_44 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_44) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_44)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_44) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_44))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_51 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_51) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_51)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_51) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_51))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_50 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_50) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_50)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_50) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_50))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_49 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_49) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_49)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_49) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_49))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_48 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_48) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_48)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_48) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_48))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_55 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_55) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_55)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_55) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_55))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_54 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_54) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_54)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_54) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_54))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_53 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_53) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_53)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_53) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_53))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_52 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_52) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_52)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_52) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_52))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_59 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_59) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_59)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_59) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_59))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_58 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_58) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_58)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_58) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_58))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_57 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_57) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_57)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_57) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_57))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_56 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_56) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_56)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_56) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_56))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_63 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_63) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_63)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_63) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_63))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_62 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_62) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_62)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_62) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_62))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_61 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_61) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_61)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_61) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_61))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_products_60 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_60) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_60)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_60) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_60))));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__stage1_valid 
        = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_valid;
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (3U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_3 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (2U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_2 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (1U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_1 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_0 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (7U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_7 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (6U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_6 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (5U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_5 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (4U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_4 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x0bU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_11 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x0aU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_10 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (9U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_9 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (8U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_8 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x0fU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_15 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x0eU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_14 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x0dU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_13 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x0cU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_12 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x13U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_19 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x12U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_18 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x11U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_17 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x10U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_16 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x17U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_23 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x16U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_22 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x15U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_21 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x14U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_20 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x1bU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_27 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x1aU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_26 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x19U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_25 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x18U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_24 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x1fU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_31 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x1eU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_30 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x1dU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_29 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x1cU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_28 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x23U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_35 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x22U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_34 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x21U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_33 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x20U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_32 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x27U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_39 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x26U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_38 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x25U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_37 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x24U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_36 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x2bU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_43 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x2aU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_42 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x29U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_41 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x28U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_40 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x2fU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_47 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x2eU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_46 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x2dU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_45 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x2cU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_44 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x33U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_51 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x32U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_50 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x31U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_49 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x30U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_48 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x37U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_55 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x36U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_54 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x35U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_53 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x34U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_52 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x3bU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_59 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x3aU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_58 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x39U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_57 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x38U == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_56 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x0000003fU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_63 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x3eU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_62 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x3dU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_61 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightEn) 
         & (0x3cU == (IData)(vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__trendLayer__DOT__weights_60 
            = vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_weightData;
    }
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_resultValid_REG 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage3_valid;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_31 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_1 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_1) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_0 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_0)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_32 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_3 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_3) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_2 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_2)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_33 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_5 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_5) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_4 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_4)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_34 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_7 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_7) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_6 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_6)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_35 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_9 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_9) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_8 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_8)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_36 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_11 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_11) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_10 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_10)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_37 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_13 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_13) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_12 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_12)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_38 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_15 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_15) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_14 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_14)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_39 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_17 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_17) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_16 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_16)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_40 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_19 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_19) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_18 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_18)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_41 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_21 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_21) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_20 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_20)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_42 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_23 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_23) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_22 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_22)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_43 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_25 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_25) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_24 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_24)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_44 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_27 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_27) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_26 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_26)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_45 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_29 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_29) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_28 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_28)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_46 
        = (0x007fffffU & (((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_31 
                                           << 1U)) 
                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_31) 
                          + ((0x00400000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_30 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_30)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_result_REG 
        = (0x00ffffffU & (((((((((((((((((0x00800000U 
                                          & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_31 
                                             << 1U)) 
                                         | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_31) 
                                        + ((0x00800000U 
                                            & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_32 
                                               << 1U)) 
                                           | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_32)) 
                                       + ((0x00800000U 
                                           & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_33 
                                              << 1U)) 
                                          | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_33)) 
                                      + ((0x00800000U 
                                          & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_34 
                                             << 1U)) 
                                         | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_34)) 
                                     + ((0x00800000U 
                                         & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_35 
                                            << 1U)) 
                                        | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_35)) 
                                    + ((0x00800000U 
                                        & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_36 
                                           << 1U)) 
                                       | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_36)) 
                                   + ((0x00800000U 
                                       & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_37 
                                          << 1U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_37)) 
                                  + ((0x00800000U & 
                                      (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_38 
                                       << 1U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_38)) 
                                 + ((0x00800000U & 
                                     (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_39 
                                      << 1U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_39)) 
                                + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_40 
                                                   << 1U)) 
                                   | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_40)) 
                               + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_41 
                                                  << 1U)) 
                                  | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_41)) 
                              + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_42 
                                                 << 1U)) 
                                 | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_42)) 
                             + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_43 
                                                << 1U)) 
                                | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_43)) 
                            + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_44 
                                               << 1U)) 
                               | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_44)) 
                           + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_45 
                                              << 1U)) 
                              | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_45)) 
                          + ((0x00800000U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_46 
                                             << 1U)) 
                             | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_46)));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_resultValid 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_resultValid_REG;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage3_valid 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_valid;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_result 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_result_REG;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_0 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_3) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_3)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_2) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_2))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_1 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_0 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_0);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_1) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_1)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_0) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_0))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_0 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_2 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_7) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_7)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_6) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_6))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_3 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_2 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_2);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_1 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_5) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_5)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_4) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_4))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_2 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_1 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_1);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_4 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_11) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_11)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_10) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_10))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_5 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_4 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_4);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_3 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_9) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_9)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_8) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_8))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_4 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_3 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_3);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_6 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_15) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_15)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_14) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_14))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_7 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_6 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_6);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_5 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_13) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_13)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_12) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_12))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_6 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_5 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_5);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_8 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_19) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_19)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_18) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_18))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_9 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_8 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_8);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_7 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_17) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_17)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_16) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_16))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_8 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_7 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_7);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_10 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_23) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_23)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_22) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_22))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_11 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_10 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_10);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_9 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_21) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_21)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_20) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_20))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_10 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_9 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_9);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_12 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_27) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_27)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_26) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_26))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_13 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_12 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_12);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_11 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_25) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_25)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_24) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_24))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_12 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_11 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_11);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_14 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_31) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_31)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_30) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_30))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_15 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_14 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_14);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_13 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_29) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_29)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_28) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_28))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_14 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_13 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_13);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_16 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_35) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_35)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_34) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_34))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_17 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_16 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_16);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_15 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_33) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_33)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_32) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_32))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_16 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_15 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_15);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_18 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_39) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_39)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_38) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_38))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_19 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_18 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_18);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_17 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_37) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_37)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_36) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_36))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_18 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_17 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_17);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_20 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_43) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_43)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_42) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_42))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_21 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_20 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_20);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_19 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_41) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_41)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_40) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_40))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_20 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_19 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_19);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_22 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_47) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_47)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_46) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_46))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_23 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_22 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_22);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_21 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_45) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_45)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_44) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_44))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_22 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_21 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_21);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_24 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_51) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_51)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_50) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_50))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_25 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_24 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_24);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_23 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_49) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_49)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_48) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_48))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_24 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_23 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_23);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_26 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_55) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_55)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_54) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_54))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_27 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_26 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_26);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_25 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_53) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_53)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_52) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_52))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_26 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_25 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_25);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_28 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_59) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_59)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_58) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_58))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_29 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_28 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_28);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_27 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_57) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_57)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_56) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_56))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_28 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_27 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_27);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_30 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_63) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_63)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_62) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_62))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_31 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_30 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_30);
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_29 
        = (0x0001ffffU & (((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_61) 
                                           << 1U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_61)) 
                          + ((0x00010000U & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_60) 
                                             << 1U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_60))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_sums_30 
        = ((0x003e0000U & ((- (IData)((1U & (vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_29 
                                             >> 0x10U)))) 
                           << 0x00000011U)) | vlSelfRef.DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_29);
    vlSelfRef.DLinearTop__DOT___seasLayer_io_resultValid 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_resultValid;
    vlSelfRef.DLinearTop__DOT___seasLayer_io_result 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_result;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage2_valid 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_valid;
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_b 
        = vlSelfRef.DLinearTop__DOT___seasLayer_io_result;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_3 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_3) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_3)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_3) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_3))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_2 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_2) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_2)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_2) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_2))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_1 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_1) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_1)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_1) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_1))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_0 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_0) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_0)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_0) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_0))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_7 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_7) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_7)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_7) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_7))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_6 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_6) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_6)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_6) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_6))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_5 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_5) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_5)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_5) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_5))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_4 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_4) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_4)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_4) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_4))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_11 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_11) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_11)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_11) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_11))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_10 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_10) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_10)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_10) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_10))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_9 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_9) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_9)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_9) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_9))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_8 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_8) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_8)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_8) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_8))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_15 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_15) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_15)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_15) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_15))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_14 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_14) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_14)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_14) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_14))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_13 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_13) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_13)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_13) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_13))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_12 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_12) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_12)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_12) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_12))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_19 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_19) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_19)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_19) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_19))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_18 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_18) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_18)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_18) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_18))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_17 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_17) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_17)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_17) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_17))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_16 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_16) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_16)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_16) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_16))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_23 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_23) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_23)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_23) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_23))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_22 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_22) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_22)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_22) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_22))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_21 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_21) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_21)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_21) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_21))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_20 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_20) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_20)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_20) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_20))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_27 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_27) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_27)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_27) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_27))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_26 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_26) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_26)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_26) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_26))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_25 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_25) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_25)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_25) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_25))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_24 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_24) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_24)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_24) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_24))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_31 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_31) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_31)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_31) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_31))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_30 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_30) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_30)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_30) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_30))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_29 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_29) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_29)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_29) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_29))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_28 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_28) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_28)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_28) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_28))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_35 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_35) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_35)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_35) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_35))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_34 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_34) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_34)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_34) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_34))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_33 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_33) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_33)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_33) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_33))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_32 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_32) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_32)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_32) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_32))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_39 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_39) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_39)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_39) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_39))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_38 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_38) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_38)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_38) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_38))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_37 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_37) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_37)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_37) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_37))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_36 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_36) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_36)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_36) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_36))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_43 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_43) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_43)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_43) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_43))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_42 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_42) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_42)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_42) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_42))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_41 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_41) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_41)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_41) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_41))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_40 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_40) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_40)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_40) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_40))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_47 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_47) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_47)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_47) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_47))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_46 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_46) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_46)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_46) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_46))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_45 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_45) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_45)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_45) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_45))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_44 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_44) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_44)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_44) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_44))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_51 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_51) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_51)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_51) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_51))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_50 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_50) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_50)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_50) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_50))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_49 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_49) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_49)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_49) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_49))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_48 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_48) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_48)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_48) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_48))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_55 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_55) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_55)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_55) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_55))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_54 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_54) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_54)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_54) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_54))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_53 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_53) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_53)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_53) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_53))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_52 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_52) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_52)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_52) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_52))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_59 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_59) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_59)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_59) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_59))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_58 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_58) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_58)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_58) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_58))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_57 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_57) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_57)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_57) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_57))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_56 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_56) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_56)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_56) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_56))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_63 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_63) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_63)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_63) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_63))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_62 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_62) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_62)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_62) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_62))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_61 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_61) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_61)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_61) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_61))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_products_60 
        = (0x0000ffffU & (((0x0000ff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_60) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_60)) 
                          * ((0x0000ff00U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_60) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_60))));
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__stage1_valid 
        = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_valid;
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (3U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_3 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (2U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_2 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (1U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_1 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_0 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (7U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_7 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (6U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_6 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (5U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_5 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (4U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_4 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x0bU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_11 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x0aU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_10 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (9U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_9 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (8U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_8 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x0fU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_15 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x0eU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_14 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x0dU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_13 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x0cU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_12 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x13U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_19 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x12U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_18 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x11U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_17 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x10U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_16 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x17U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_23 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x16U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_22 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x15U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_21 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x14U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_20 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x1bU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_27 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x1aU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_26 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x19U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_25 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x18U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_24 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x1fU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_31 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x1eU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_30 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x1dU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_29 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x1cU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_28 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x23U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_35 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x22U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_34 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x21U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_33 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x20U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_32 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x27U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_39 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x26U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_38 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x25U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_37 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x24U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_36 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x2bU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_43 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x2aU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_42 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x29U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_41 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x28U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_40 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x2fU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_47 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x2eU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_46 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x2dU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_45 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x2cU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_44 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x33U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_51 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x32U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_50 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x31U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_49 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x30U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_48 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x37U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_55 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x36U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_54 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x35U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_53 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x34U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_52 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x3bU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_59 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x3aU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_58 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x39U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_57 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x38U == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_56 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x0000003fU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_63 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x3eU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_62 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x3dU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_61 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
    if (((IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightEn) 
         & (0x3cU == (IData)(vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightAddr)))) {
        vlSelfRef.DLinearTop__DOT__seasLayer__DOT__weights_60 
            = vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_weightData;
    }
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ DLinearTop__DOT____Vcellinp__seasLayer__io_valid;
    DLinearTop__DOT____Vcellinp__seasLayer__io_valid = 0;
    // Body
    vlSelfRef.DLinearTop__DOT__io_status_ready = ((IData)(vlSelfRef.DLinearTop__DOT___decomp_io_ready) 
                                                  & ((IData)(vlSelfRef.DLinearTop__DOT__windowFillCount) 
                                                     >> 6U));
    vlSelfRef.DLinearTop__DOT___seasLayer_io_valid_T 
        = (((IData)(vlSelfRef.DLinearTop__DOT__windowFillCount) 
            >> 6U) & (IData)(vlSelfRef.DLinearTop__DOT___decomp_io_ready));
    vlSelfRef.io_status_ready = vlSelfRef.DLinearTop__DOT__io_status_ready;
    DLinearTop__DOT____Vcellinp__seasLayer__io_valid 
        = ((IData)(vlSelfRef.DLinearTop__DOT___seasLayer_io_valid_T) 
           & (IData)(vlSelfRef.DLinearTop__DOT____Vcellinp__decomp__io_valid));
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_valid 
        = DLinearTop__DOT____Vcellinp__seasLayer__io_valid;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_valid 
        = DLinearTop__DOT____Vcellinp__seasLayer__io_valid;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_3 
        = vlSelfRef.DLinearTop__DOT__trendWindow_3;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_2 
        = vlSelfRef.DLinearTop__DOT__trendWindow_2;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_1 
        = vlSelfRef.DLinearTop__DOT__trendWindow_1;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_0 
        = vlSelfRef.DLinearTop__DOT__trendWindow_0;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_7 
        = vlSelfRef.DLinearTop__DOT__trendWindow_7;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_6 
        = vlSelfRef.DLinearTop__DOT__trendWindow_6;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_5 
        = vlSelfRef.DLinearTop__DOT__trendWindow_5;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_4 
        = vlSelfRef.DLinearTop__DOT__trendWindow_4;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_11 
        = vlSelfRef.DLinearTop__DOT__trendWindow_11;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_10 
        = vlSelfRef.DLinearTop__DOT__trendWindow_10;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_9 
        = vlSelfRef.DLinearTop__DOT__trendWindow_9;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_8 
        = vlSelfRef.DLinearTop__DOT__trendWindow_8;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_15 
        = vlSelfRef.DLinearTop__DOT__trendWindow_15;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_14 
        = vlSelfRef.DLinearTop__DOT__trendWindow_14;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_13 
        = vlSelfRef.DLinearTop__DOT__trendWindow_13;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_12 
        = vlSelfRef.DLinearTop__DOT__trendWindow_12;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_19 
        = vlSelfRef.DLinearTop__DOT__trendWindow_19;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_18 
        = vlSelfRef.DLinearTop__DOT__trendWindow_18;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_17 
        = vlSelfRef.DLinearTop__DOT__trendWindow_17;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_16 
        = vlSelfRef.DLinearTop__DOT__trendWindow_16;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_23 
        = vlSelfRef.DLinearTop__DOT__trendWindow_23;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_22 
        = vlSelfRef.DLinearTop__DOT__trendWindow_22;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_21 
        = vlSelfRef.DLinearTop__DOT__trendWindow_21;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_20 
        = vlSelfRef.DLinearTop__DOT__trendWindow_20;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_27 
        = vlSelfRef.DLinearTop__DOT__trendWindow_27;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_26 
        = vlSelfRef.DLinearTop__DOT__trendWindow_26;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_25 
        = vlSelfRef.DLinearTop__DOT__trendWindow_25;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_24 
        = vlSelfRef.DLinearTop__DOT__trendWindow_24;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_31 
        = vlSelfRef.DLinearTop__DOT__trendWindow_31;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_30 
        = vlSelfRef.DLinearTop__DOT__trendWindow_30;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_29 
        = vlSelfRef.DLinearTop__DOT__trendWindow_29;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_28 
        = vlSelfRef.DLinearTop__DOT__trendWindow_28;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_35 
        = vlSelfRef.DLinearTop__DOT__trendWindow_35;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_34 
        = vlSelfRef.DLinearTop__DOT__trendWindow_34;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_33 
        = vlSelfRef.DLinearTop__DOT__trendWindow_33;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_32 
        = vlSelfRef.DLinearTop__DOT__trendWindow_32;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_39 
        = vlSelfRef.DLinearTop__DOT__trendWindow_39;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_38 
        = vlSelfRef.DLinearTop__DOT__trendWindow_38;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_37 
        = vlSelfRef.DLinearTop__DOT__trendWindow_37;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_36 
        = vlSelfRef.DLinearTop__DOT__trendWindow_36;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_43 
        = vlSelfRef.DLinearTop__DOT__trendWindow_43;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_42 
        = vlSelfRef.DLinearTop__DOT__trendWindow_42;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_41 
        = vlSelfRef.DLinearTop__DOT__trendWindow_41;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_40 
        = vlSelfRef.DLinearTop__DOT__trendWindow_40;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_47 
        = vlSelfRef.DLinearTop__DOT__trendWindow_47;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_46 
        = vlSelfRef.DLinearTop__DOT__trendWindow_46;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_45 
        = vlSelfRef.DLinearTop__DOT__trendWindow_45;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_44 
        = vlSelfRef.DLinearTop__DOT__trendWindow_44;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_51 
        = vlSelfRef.DLinearTop__DOT__trendWindow_51;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_50 
        = vlSelfRef.DLinearTop__DOT__trendWindow_50;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_49 
        = vlSelfRef.DLinearTop__DOT__trendWindow_49;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_48 
        = vlSelfRef.DLinearTop__DOT__trendWindow_48;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_55 
        = vlSelfRef.DLinearTop__DOT__trendWindow_55;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_54 
        = vlSelfRef.DLinearTop__DOT__trendWindow_54;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_53 
        = vlSelfRef.DLinearTop__DOT__trendWindow_53;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_52 
        = vlSelfRef.DLinearTop__DOT__trendWindow_52;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_59 
        = vlSelfRef.DLinearTop__DOT__trendWindow_59;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_58 
        = vlSelfRef.DLinearTop__DOT__trendWindow_58;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_57 
        = vlSelfRef.DLinearTop__DOT__trendWindow_57;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_56 
        = vlSelfRef.DLinearTop__DOT__trendWindow_56;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_63 
        = vlSelfRef.DLinearTop__DOT__trendWindow_63;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_62 
        = vlSelfRef.DLinearTop__DOT__trendWindow_62;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_61 
        = vlSelfRef.DLinearTop__DOT__trendWindow_61;
    vlSelfRef.DLinearTop__DOT__trendLayer__DOT__io_in_60 
        = vlSelfRef.DLinearTop__DOT__trendWindow_60;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_3 
        = vlSelfRef.DLinearTop__DOT__seasWindow_3;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_2 
        = vlSelfRef.DLinearTop__DOT__seasWindow_2;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_1 
        = vlSelfRef.DLinearTop__DOT__seasWindow_1;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_0 
        = vlSelfRef.DLinearTop__DOT__seasWindow_0;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_7 
        = vlSelfRef.DLinearTop__DOT__seasWindow_7;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_6 
        = vlSelfRef.DLinearTop__DOT__seasWindow_6;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_5 
        = vlSelfRef.DLinearTop__DOT__seasWindow_5;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_4 
        = vlSelfRef.DLinearTop__DOT__seasWindow_4;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_11 
        = vlSelfRef.DLinearTop__DOT__seasWindow_11;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_10 
        = vlSelfRef.DLinearTop__DOT__seasWindow_10;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_9 
        = vlSelfRef.DLinearTop__DOT__seasWindow_9;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_8 
        = vlSelfRef.DLinearTop__DOT__seasWindow_8;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_15 
        = vlSelfRef.DLinearTop__DOT__seasWindow_15;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_14 
        = vlSelfRef.DLinearTop__DOT__seasWindow_14;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_13 
        = vlSelfRef.DLinearTop__DOT__seasWindow_13;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_12 
        = vlSelfRef.DLinearTop__DOT__seasWindow_12;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_19 
        = vlSelfRef.DLinearTop__DOT__seasWindow_19;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_18 
        = vlSelfRef.DLinearTop__DOT__seasWindow_18;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_17 
        = vlSelfRef.DLinearTop__DOT__seasWindow_17;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_16 
        = vlSelfRef.DLinearTop__DOT__seasWindow_16;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_23 
        = vlSelfRef.DLinearTop__DOT__seasWindow_23;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_22 
        = vlSelfRef.DLinearTop__DOT__seasWindow_22;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_21 
        = vlSelfRef.DLinearTop__DOT__seasWindow_21;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_20 
        = vlSelfRef.DLinearTop__DOT__seasWindow_20;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_27 
        = vlSelfRef.DLinearTop__DOT__seasWindow_27;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_26 
        = vlSelfRef.DLinearTop__DOT__seasWindow_26;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_25 
        = vlSelfRef.DLinearTop__DOT__seasWindow_25;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_24 
        = vlSelfRef.DLinearTop__DOT__seasWindow_24;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_31 
        = vlSelfRef.DLinearTop__DOT__seasWindow_31;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_30 
        = vlSelfRef.DLinearTop__DOT__seasWindow_30;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_29 
        = vlSelfRef.DLinearTop__DOT__seasWindow_29;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_28 
        = vlSelfRef.DLinearTop__DOT__seasWindow_28;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_35 
        = vlSelfRef.DLinearTop__DOT__seasWindow_35;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_34 
        = vlSelfRef.DLinearTop__DOT__seasWindow_34;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_33 
        = vlSelfRef.DLinearTop__DOT__seasWindow_33;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_32 
        = vlSelfRef.DLinearTop__DOT__seasWindow_32;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_39 
        = vlSelfRef.DLinearTop__DOT__seasWindow_39;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_38 
        = vlSelfRef.DLinearTop__DOT__seasWindow_38;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_37 
        = vlSelfRef.DLinearTop__DOT__seasWindow_37;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_36 
        = vlSelfRef.DLinearTop__DOT__seasWindow_36;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_43 
        = vlSelfRef.DLinearTop__DOT__seasWindow_43;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_42 
        = vlSelfRef.DLinearTop__DOT__seasWindow_42;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_41 
        = vlSelfRef.DLinearTop__DOT__seasWindow_41;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_40 
        = vlSelfRef.DLinearTop__DOT__seasWindow_40;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_47 
        = vlSelfRef.DLinearTop__DOT__seasWindow_47;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_46 
        = vlSelfRef.DLinearTop__DOT__seasWindow_46;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_45 
        = vlSelfRef.DLinearTop__DOT__seasWindow_45;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_44 
        = vlSelfRef.DLinearTop__DOT__seasWindow_44;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_51 
        = vlSelfRef.DLinearTop__DOT__seasWindow_51;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_50 
        = vlSelfRef.DLinearTop__DOT__seasWindow_50;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_49 
        = vlSelfRef.DLinearTop__DOT__seasWindow_49;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_48 
        = vlSelfRef.DLinearTop__DOT__seasWindow_48;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_55 
        = vlSelfRef.DLinearTop__DOT__seasWindow_55;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_54 
        = vlSelfRef.DLinearTop__DOT__seasWindow_54;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_53 
        = vlSelfRef.DLinearTop__DOT__seasWindow_53;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_52 
        = vlSelfRef.DLinearTop__DOT__seasWindow_52;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_59 
        = vlSelfRef.DLinearTop__DOT__seasWindow_59;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_58 
        = vlSelfRef.DLinearTop__DOT__seasWindow_58;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_57 
        = vlSelfRef.DLinearTop__DOT__seasWindow_57;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_56 
        = vlSelfRef.DLinearTop__DOT__seasWindow_56;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_63 
        = vlSelfRef.DLinearTop__DOT__seasWindow_63;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_62 
        = vlSelfRef.DLinearTop__DOT__seasWindow_62;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_61 
        = vlSelfRef.DLinearTop__DOT__seasWindow_61;
    vlSelfRef.DLinearTop__DOT__seasLayer__DOT__io_in_60 
        = vlSelfRef.DLinearTop__DOT__seasWindow_60;
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.DLinearTop__DOT__fusionAdder__DOT__io_valid 
        = ((IData)(vlSelfRef.DLinearTop__DOT___seasLayer_io_resultValid) 
           & (IData)(vlSelfRef.DLinearTop__DOT___trendLayer_io_resultValid));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/Users/kirill/aperion/verification/../hardware/generated/DLinearTop.sv", 1171, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/kirill/aperion/verification/../hardware/generated/DLinearTop.sv", 1171, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/kirill/aperion/verification/../hardware/generated/DLinearTop.sv", 1171, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_dataValid & 0xfeU)))) {
        Verilated::overWidthError("io_dataValid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_configMode & 0xfeU)))) {
        Verilated::overWidthError("io_configMode");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_config_addr & 0xc0U)))) {
        Verilated::overWidthError("io_config_addr");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_config_writeEn & 0xfeU)))) {
        Verilated::overWidthError("io_config_writeEn");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_config_weightSel 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_config_weightSel");
    }
}
#endif  // VL_DEBUG
