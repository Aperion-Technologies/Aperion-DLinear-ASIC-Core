// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/kirill/aperion/verification/../hardware/generated/DLinearTop.sv", 1171, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge DLinearTop.clock)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge DLinearTop.decomp.clock)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge DLinearTop.trendLayer.clock)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge DLinearTop.seasLayer.clock)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge DLinearTop.fusionAdder.clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5452235342940299466ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->io_dataIn = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6238546677346096030ull);
    vlSelf->io_dataValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15566161173904868938ull);
    vlSelf->io_predOut = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8881832867341217702ull);
    vlSelf->io_predValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10133694875396583921ull);
    vlSelf->io_configMode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17255569747000123945ull);
    vlSelf->io_config_addr = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 16462459906616200356ull);
    vlSelf->io_config_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1471120413365165184ull);
    vlSelf->io_config_writeEn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14827733977607384482ull);
    vlSelf->io_config_weightSel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1252507514526530566ull);
    vlSelf->io_status_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14554755859361907628ull);
    vlSelf->io_status_weightsLoaded = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9743811018559306153ull);
    vlSelf->DLinearTop__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2534509380336847996ull);
    vlSelf->DLinearTop__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12998081669910548185ull);
    vlSelf->DLinearTop__DOT__io_dataIn = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2862454956633526315ull);
    vlSelf->DLinearTop__DOT__io_dataValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16088851413571378773ull);
    vlSelf->DLinearTop__DOT__io_predOut = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16323401891711135897ull);
    vlSelf->DLinearTop__DOT__io_predValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16824474677652941452ull);
    vlSelf->DLinearTop__DOT__io_configMode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3801145473401480582ull);
    vlSelf->DLinearTop__DOT__io_config_addr = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 234261239280423339ull);
    vlSelf->DLinearTop__DOT__io_config_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12229074861286066079ull);
    vlSelf->DLinearTop__DOT__io_config_writeEn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10319168792442952294ull);
    vlSelf->DLinearTop__DOT__io_config_weightSel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 450125402212427908ull);
    vlSelf->DLinearTop__DOT__io_status_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13224849463087779293ull);
    vlSelf->DLinearTop__DOT__io_status_weightsLoaded = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1745180131717535279ull);
    vlSelf->DLinearTop__DOT___seasLayer_io_result = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8532454226492660353ull);
    vlSelf->DLinearTop__DOT___seasLayer_io_resultValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16102682060955496993ull);
    vlSelf->DLinearTop__DOT___trendLayer_io_result = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5210317708462783352ull);
    vlSelf->DLinearTop__DOT___trendLayer_io_resultValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16956457440548546703ull);
    vlSelf->DLinearTop__DOT___decomp_io_trend = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8617937128244891525ull);
    vlSelf->DLinearTop__DOT___decomp_io_seasonal = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9905121827234885341ull);
    vlSelf->DLinearTop__DOT___decomp_io_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14061789450933876279ull);
    vlSelf->DLinearTop__DOT__weightsLoadedReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2769288404979660255ull);
    vlSelf->DLinearTop__DOT___seasLayer_io_weightEn_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14458041274343158045ull);
    vlSelf->DLinearTop__DOT__trendWindow_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15190460930932056005ull);
    vlSelf->DLinearTop__DOT__trendWindow_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3605251373147794105ull);
    vlSelf->DLinearTop__DOT__trendWindow_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 615058571279705203ull);
    vlSelf->DLinearTop__DOT__trendWindow_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2478298778893625838ull);
    vlSelf->DLinearTop__DOT__trendWindow_4 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16337522753250330163ull);
    vlSelf->DLinearTop__DOT__trendWindow_5 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18317768681059230508ull);
    vlSelf->DLinearTop__DOT__trendWindow_6 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11808042567037814606ull);
    vlSelf->DLinearTop__DOT__trendWindow_7 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12495691862056444806ull);
    vlSelf->DLinearTop__DOT__trendWindow_8 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16120921537173534564ull);
    vlSelf->DLinearTop__DOT__trendWindow_9 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3200176352308464924ull);
    vlSelf->DLinearTop__DOT__trendWindow_10 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8871630600650493231ull);
    vlSelf->DLinearTop__DOT__trendWindow_11 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13376964570261864684ull);
    vlSelf->DLinearTop__DOT__trendWindow_12 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14002184905445977401ull);
    vlSelf->DLinearTop__DOT__trendWindow_13 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11294789751026990400ull);
    vlSelf->DLinearTop__DOT__trendWindow_14 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2041461075530746245ull);
    vlSelf->DLinearTop__DOT__trendWindow_15 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7858033144471933594ull);
    vlSelf->DLinearTop__DOT__trendWindow_16 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5235903484026599564ull);
    vlSelf->DLinearTop__DOT__trendWindow_17 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15438253702686601970ull);
    vlSelf->DLinearTop__DOT__trendWindow_18 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15902802312696656748ull);
    vlSelf->DLinearTop__DOT__trendWindow_19 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5298434172555047923ull);
    vlSelf->DLinearTop__DOT__trendWindow_20 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 669110790382109599ull);
    vlSelf->DLinearTop__DOT__trendWindow_21 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16673612316198932115ull);
    vlSelf->DLinearTop__DOT__trendWindow_22 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17998767432920900661ull);
    vlSelf->DLinearTop__DOT__trendWindow_23 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5377995915798075895ull);
    vlSelf->DLinearTop__DOT__trendWindow_24 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15413623173257916507ull);
    vlSelf->DLinearTop__DOT__trendWindow_25 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2109031427780748924ull);
    vlSelf->DLinearTop__DOT__trendWindow_26 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5406768996999849275ull);
    vlSelf->DLinearTop__DOT__trendWindow_27 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7319099699396529331ull);
    vlSelf->DLinearTop__DOT__trendWindow_28 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5292564562890347138ull);
    vlSelf->DLinearTop__DOT__trendWindow_29 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10367571687786220723ull);
    vlSelf->DLinearTop__DOT__trendWindow_30 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15098496160409935297ull);
    vlSelf->DLinearTop__DOT__trendWindow_31 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7773707690759534679ull);
    vlSelf->DLinearTop__DOT__trendWindow_32 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16353363305131681838ull);
    vlSelf->DLinearTop__DOT__trendWindow_33 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2472489820795540812ull);
    vlSelf->DLinearTop__DOT__trendWindow_34 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 761431335775643351ull);
    vlSelf->DLinearTop__DOT__trendWindow_35 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10395839798641238968ull);
    vlSelf->DLinearTop__DOT__trendWindow_36 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4800241204840405686ull);
    vlSelf->DLinearTop__DOT__trendWindow_37 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13482496456070725301ull);
    vlSelf->DLinearTop__DOT__trendWindow_38 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1892940820313201648ull);
    vlSelf->DLinearTop__DOT__trendWindow_39 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14181878784933029374ull);
    vlSelf->DLinearTop__DOT__trendWindow_40 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1711771146715405925ull);
    vlSelf->DLinearTop__DOT__trendWindow_41 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18301283435633563850ull);
    vlSelf->DLinearTop__DOT__trendWindow_42 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2471354657317901099ull);
    vlSelf->DLinearTop__DOT__trendWindow_43 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2718132937821702824ull);
    vlSelf->DLinearTop__DOT__trendWindow_44 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12631344028950862090ull);
    vlSelf->DLinearTop__DOT__trendWindow_45 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11526172772591499749ull);
    vlSelf->DLinearTop__DOT__trendWindow_46 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7692321102127298513ull);
    vlSelf->DLinearTop__DOT__trendWindow_47 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7536157841302997303ull);
    vlSelf->DLinearTop__DOT__trendWindow_48 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10167020265009311696ull);
    vlSelf->DLinearTop__DOT__trendWindow_49 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 650049628804400865ull);
    vlSelf->DLinearTop__DOT__trendWindow_50 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14790477953111435381ull);
    vlSelf->DLinearTop__DOT__trendWindow_51 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 690358066746772335ull);
    vlSelf->DLinearTop__DOT__trendWindow_52 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18162713541390351988ull);
    vlSelf->DLinearTop__DOT__trendWindow_53 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14206984609642096285ull);
    vlSelf->DLinearTop__DOT__trendWindow_54 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16134202210124800450ull);
    vlSelf->DLinearTop__DOT__trendWindow_55 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4762435933734241398ull);
    vlSelf->DLinearTop__DOT__trendWindow_56 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1693897119505494373ull);
    vlSelf->DLinearTop__DOT__trendWindow_57 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11516205873857229193ull);
    vlSelf->DLinearTop__DOT__trendWindow_58 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8676578497520884409ull);
    vlSelf->DLinearTop__DOT__trendWindow_59 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16261682445140204247ull);
    vlSelf->DLinearTop__DOT__trendWindow_60 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14797260232932203398ull);
    vlSelf->DLinearTop__DOT__trendWindow_61 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2327918451098193197ull);
    vlSelf->DLinearTop__DOT__trendWindow_62 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5411357123682420428ull);
    vlSelf->DLinearTop__DOT__trendWindow_63 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6283362513184737375ull);
    vlSelf->DLinearTop__DOT__seasWindow_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15865659935629144328ull);
    vlSelf->DLinearTop__DOT__seasWindow_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7831617924097841000ull);
    vlSelf->DLinearTop__DOT__seasWindow_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8622512585309148354ull);
    vlSelf->DLinearTop__DOT__seasWindow_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5033477577106886087ull);
    vlSelf->DLinearTop__DOT__seasWindow_4 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15229106249171395389ull);
    vlSelf->DLinearTop__DOT__seasWindow_5 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1242896443310287377ull);
    vlSelf->DLinearTop__DOT__seasWindow_6 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7316274562619757785ull);
    vlSelf->DLinearTop__DOT__seasWindow_7 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12446493166699750367ull);
    vlSelf->DLinearTop__DOT__seasWindow_8 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10567025855728622735ull);
    vlSelf->DLinearTop__DOT__seasWindow_9 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13349638938200503840ull);
    vlSelf->DLinearTop__DOT__seasWindow_10 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1962565211901581941ull);
    vlSelf->DLinearTop__DOT__seasWindow_11 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 822396153677129208ull);
    vlSelf->DLinearTop__DOT__seasWindow_12 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9365782160191476248ull);
    vlSelf->DLinearTop__DOT__seasWindow_13 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11219564666070099755ull);
    vlSelf->DLinearTop__DOT__seasWindow_14 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7229822056873919329ull);
    vlSelf->DLinearTop__DOT__seasWindow_15 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17133213099756579322ull);
    vlSelf->DLinearTop__DOT__seasWindow_16 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2785047128310842175ull);
    vlSelf->DLinearTop__DOT__seasWindow_17 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8788211545562494824ull);
    vlSelf->DLinearTop__DOT__seasWindow_18 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9807551555996085052ull);
    vlSelf->DLinearTop__DOT__seasWindow_19 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 361082571063390611ull);
    vlSelf->DLinearTop__DOT__seasWindow_20 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1269038966660289272ull);
    vlSelf->DLinearTop__DOT__seasWindow_21 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3396603881797797896ull);
    vlSelf->DLinearTop__DOT__seasWindow_22 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10586922640955667476ull);
    vlSelf->DLinearTop__DOT__seasWindow_23 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10144651273078452803ull);
    vlSelf->DLinearTop__DOT__seasWindow_24 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12919534298904090627ull);
    vlSelf->DLinearTop__DOT__seasWindow_25 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7729603009747101293ull);
    vlSelf->DLinearTop__DOT__seasWindow_26 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10909630108318081061ull);
    vlSelf->DLinearTop__DOT__seasWindow_27 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16319370262834736411ull);
    vlSelf->DLinearTop__DOT__seasWindow_28 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10439492297068624117ull);
    vlSelf->DLinearTop__DOT__seasWindow_29 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14787952050418483634ull);
    vlSelf->DLinearTop__DOT__seasWindow_30 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12613819601931756891ull);
    vlSelf->DLinearTop__DOT__seasWindow_31 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1373935550031630929ull);
    vlSelf->DLinearTop__DOT__seasWindow_32 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15752173705655060304ull);
    vlSelf->DLinearTop__DOT__seasWindow_33 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7125865562666280708ull);
    vlSelf->DLinearTop__DOT__seasWindow_34 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9395296052338074310ull);
    vlSelf->DLinearTop__DOT__seasWindow_35 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10019154489585326641ull);
    vlSelf->DLinearTop__DOT__seasWindow_36 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10467132972665686982ull);
    vlSelf->DLinearTop__DOT__seasWindow_37 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17038331535169355208ull);
    vlSelf->DLinearTop__DOT__seasWindow_38 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4630392352903342123ull);
    vlSelf->DLinearTop__DOT__seasWindow_39 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14303844521288967721ull);
    vlSelf->DLinearTop__DOT__seasWindow_40 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3814105272079789057ull);
    vlSelf->DLinearTop__DOT__seasWindow_41 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1180292734973773726ull);
    vlSelf->DLinearTop__DOT__seasWindow_42 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1186263591052222132ull);
    vlSelf->DLinearTop__DOT__seasWindow_43 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6671660317998866125ull);
    vlSelf->DLinearTop__DOT__seasWindow_44 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3124747329006549927ull);
    vlSelf->DLinearTop__DOT__seasWindow_45 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13851277228917806932ull);
    vlSelf->DLinearTop__DOT__seasWindow_46 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14867646129950868528ull);
    vlSelf->DLinearTop__DOT__seasWindow_47 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10590662545854455080ull);
    vlSelf->DLinearTop__DOT__seasWindow_48 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4890814100120566152ull);
    vlSelf->DLinearTop__DOT__seasWindow_49 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10464287121279655783ull);
    vlSelf->DLinearTop__DOT__seasWindow_50 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11355812626613423053ull);
    vlSelf->DLinearTop__DOT__seasWindow_51 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2662530840738065022ull);
    vlSelf->DLinearTop__DOT__seasWindow_52 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11892717716556175945ull);
    vlSelf->DLinearTop__DOT__seasWindow_53 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5711593692488949286ull);
    vlSelf->DLinearTop__DOT__seasWindow_54 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4527485014725610166ull);
    vlSelf->DLinearTop__DOT__seasWindow_55 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15488054647807930741ull);
    vlSelf->DLinearTop__DOT__seasWindow_56 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10182693363587296144ull);
    vlSelf->DLinearTop__DOT__seasWindow_57 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7992944037300531700ull);
    vlSelf->DLinearTop__DOT__seasWindow_58 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16627316811410254540ull);
    vlSelf->DLinearTop__DOT__seasWindow_59 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8295844300401008997ull);
    vlSelf->DLinearTop__DOT__seasWindow_60 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4510902459464734710ull);
    vlSelf->DLinearTop__DOT__seasWindow_61 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15379103777586697217ull);
    vlSelf->DLinearTop__DOT__seasWindow_62 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9010388184822321739ull);
    vlSelf->DLinearTop__DOT__seasWindow_63 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8326535654433634254ull);
    vlSelf->DLinearTop__DOT__windowFillCount = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 16034787594675282554ull);
    vlSelf->DLinearTop__DOT___seasLayer_io_valid_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13408363893169776385ull);
    vlSelf->DLinearTop__DOT____Vcellinp__decomp__io_valid = 0;
    vlSelf->DLinearTop__DOT__unnamedblk1__DOT___GEN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16812912939136740387ull);
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->DLinearTop__DOT__unnamedblk2__DOT___RANDOM[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9599181270512706103ull);
    }
    vlSelf->DLinearTop__DOT__decomp__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6025580027125012571ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15025673397729397640ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__io_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5610387232504415218ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__io_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 933763602449967773ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__io_trend = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2252274352379693727ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__io_seasonal = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17979785930055000838ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__io_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6016549554003621536ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7742520979056275863ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2707325423707629777ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1078933840091798096ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9936523617512703089ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_4 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 931215369915962047ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_5 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13393367420058451650ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_6 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10320366055413732830ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_7 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13877837954484507136ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_8 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17549564249218701416ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_9 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8363739966941458135ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_10 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5172828756820724171ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_11 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14461858352398378545ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_12 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14201521707494650843ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_13 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13569329480445509395ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_14 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11771378879395873957ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_15 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14382225445331291510ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_16 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12102905620291369420ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_17 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 966070995891615617ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_18 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15219496530342320410ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_19 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12328189034318687454ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_20 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1894255679153283939ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_21 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15575813219137208177ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_22 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1221397411061457678ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_23 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3164043778684703989ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_24 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13775289259826725858ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_25 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7105549041259843174ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_26 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6845212396356005907ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_27 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4059146008898145856ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_28 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17641403069198289066ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_29 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16569869634427400899ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_30 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14968877033632339205ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_31 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17579723599567990102ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_32 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15300403774527788587ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_33 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17556688756329935226ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_34 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12984690441724248968ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_35 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15639463982602335287ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_36 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3900739417844790209ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_37 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8971995083157443620ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_38 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10259485556560914501ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_39 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6498684031822626972ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_40 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17306887513219507785ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_41 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10952870620350202929ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_42 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10042710550592536816ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_43 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7151403054568937396ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_44 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1116241813708690325ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_45 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17643374363033118729ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_46 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2661611005291078050ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_47 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4456078904183737500ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_48 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6549734882468710058ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_49 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6338507089683151121ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_50 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16182188595961001320ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_51 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6322524946081314430ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_52 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7098237572081328865ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_53 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12398352227984414750ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_54 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11949241108352331214ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_55 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3218640285571169383ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_56 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2447293926047739923ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_57 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12581433335401170430ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_58 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12217648490147603587ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_59 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2638969577752386475ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_60 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16385867675142513410ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_61 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1283618761687484218ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_62 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11791416042479582234ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__shiftReg_63 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7653577058420288511ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__fillCount = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 2177892056565315861ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__runningSum = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 15462234834883174586ull);
    vlSelf->DLinearTop__DOT__decomp__DOT__unnamedblk1__DOT___GEN = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 17722164520272682703ull);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->DLinearTop__DOT__decomp__DOT__unnamedblk2__DOT___RANDOM[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8199284334735692944ull);
    }
    vlSelf->DLinearTop__DOT__trendLayer__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4756281409506444402ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6309978797631660657ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4204304431708338602ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1587138717812362471ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3614458658565788492ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_4 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5362335999769092546ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_5 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13761304031196575416ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_6 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13048692002141528707ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_7 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3335016059015594611ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_8 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11888864303417775987ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_9 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1841088261135550373ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_10 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12514376567864918459ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_11 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18142782001046176069ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_12 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6930232896266864265ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_13 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1811814292394581313ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_14 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12717186485092281484ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_15 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6723124631417928448ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_16 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9016110237925660248ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_17 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1722401534543941442ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_18 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13706725197655944010ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_19 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8881554044293823216ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_20 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1992102972709445935ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_21 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13709122208215883400ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_22 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4873157033348474390ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_23 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3836666925345479233ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_24 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16165303849775031044ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_25 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15453725454198926883ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_26 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10820267491583388046ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_27 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15958195584926114973ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_28 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3990581946727429804ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_29 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12527926073737018703ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_30 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4140573487684853365ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_31 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9686213687487507110ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_32 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 439497240518230201ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_33 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10190683818214709497ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_34 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1364931805508754383ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_35 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13071737878853822402ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_36 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6609317468256203954ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_37 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7812505919682630126ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_38 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7646142362899936907ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_39 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15976043438419739975ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_40 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 940308286622541502ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_41 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5511213349144698171ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_42 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12213053554158436480ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_43 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13091330293157899496ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_44 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1929846999186125564ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_45 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13595800423885085198ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_46 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3412091432835765514ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_47 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11278267085694784335ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_48 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5487015149247826110ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_49 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4104268279521047024ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_50 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14609079306184261223ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_51 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1571070061794920414ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_52 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14361524069133723186ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_53 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16316737888337856726ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_54 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9038928425474872753ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_55 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3879657172956696359ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_56 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 326175456187466970ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_57 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17746642584055461354ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_58 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14217615972028831927ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_59 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4869195885520283755ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_60 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15680612740955119673ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_61 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10301670884576063636ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_62 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11434954177500805776ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_in_63 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18464329603719912ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2151771364458400347ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_result = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17246321951827637341ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_resultValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11326801841155656369ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_weightEn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9827179906056634243ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_weightAddr = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 2873111521502375218ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_weightData = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16135355929080692528ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3887447369132533178ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8651027207098410848ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8924842073720358773ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 524161296075091309ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_4 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8130047466231086464ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_5 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12028727468846910520ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_6 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10063287977872152516ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_7 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11248244785778034490ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_8 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 942780811783039141ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_9 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9899679475271507304ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_10 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16448074527488203940ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_11 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4441031178260576765ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_12 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3890453413574465769ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_13 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9692761738300860623ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_14 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 79329814653312002ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_15 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3838865905192424368ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_16 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14217319187718046322ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_17 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11218475713271823254ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_18 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16511957003435988592ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_19 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 747728419253781062ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_20 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16650318048616373712ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_21 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15191190233184024866ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_22 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10827606083633744680ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_23 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13970452890283746350ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_24 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16278799284576172498ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_25 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 896516624730561342ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_26 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10009272820836058069ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_27 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2564660507276483976ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_28 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5589544839391223099ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_29 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17228182979076537080ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_30 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12390790906445079721ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_31 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18157043218524180959ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_32 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6765147844075727511ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_33 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6546618747505680572ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_34 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15929043080292921297ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_35 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 827418352439676240ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_36 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5503408120439732596ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_37 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11850966952205652393ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_38 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11907389829773695464ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_39 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2157067509760940637ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_40 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10738692561349285846ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_41 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8669642715090260335ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_42 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11503897385752582064ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_43 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3430185810391161570ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_44 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 125649808290189401ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_45 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1280852096659738348ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_46 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7125043048757860945ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_47 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1581275350838905514ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_48 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11568796402395557009ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_49 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15670545932865169081ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_50 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3269477029121903316ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_51 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9410562414878464031ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_52 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14231366878335163943ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_53 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15005870978883535968ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_54 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3859562661445416493ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_55 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14380270638942818266ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_56 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12602906019308378243ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_57 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16043212189566190229ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_58 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16269804577249412113ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_59 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12005841198237233056ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_60 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15053960480546304078ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_61 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11934099572328404257ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_62 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10395125688109023350ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__weights_63 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3430390163443735453ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13076022700727369579ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15346495242689216872ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3553457218160179593ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_3 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17063104316111074231ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_4 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12653061286846718892ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_5 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12571334113835662143ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_6 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11547666891351107842ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_7 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11357659444132207738ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_8 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7436009722126679953ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_9 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4225673251426286210ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_10 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15641219626536094835ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_11 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9727883755454271019ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_12 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13694759750926967636ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_13 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6758505926435500630ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_14 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3951846008377307857ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_15 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6313128428950026424ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_16 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17296153641412222580ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_17 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7086259215390481164ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_18 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3856698523461031439ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_19 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8841588239429659002ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_20 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18285647713122342743ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_21 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10151221722244635800ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_22 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9749625547071748333ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_23 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1845528216799749657ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_24 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4560691496272748962ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_25 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7275391511897460686ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_26 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7056186988469964958ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_27 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3310765972283809073ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_28 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4094225007271702404ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_29 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1361392096695321209ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_30 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14509161067278525265ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_31 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12903806247278106503ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_32 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4212382838258804122ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_33 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15209541184377357061ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_34 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1952924026667318372ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_35 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3329489969087653979ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_36 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10288094013549700884ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_37 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15539259205478109902ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_38 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11055676438953699452ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_39 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8585789477490762538ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_40 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7084704071067594536ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_41 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 847378641509645681ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_42 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8912243963438550860ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_43 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14597284376741457145ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_44 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4692569769250855787ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_45 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 265353592195341994ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_46 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9176653595622740814ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_47 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5944128249251164962ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_48 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12019976590872785663ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_49 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13958684244506820730ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_50 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14428975714382086442ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_51 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12606556695762574754ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_52 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11441058883676751638ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_53 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7151101278929664962ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_54 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4941461945197213749ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_55 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5985976785448064056ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_56 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8106494408754410893ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_57 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10808921879060455856ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_58 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11365293368857162819ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_59 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12072924955186387333ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_60 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7491458988487155573ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_61 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11172847654690146152ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_62 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8576049518587459852ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_products_63 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3649576344514306644ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7512833236374531993ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_0 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 10333393244690167390ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_1 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 12345756146793597261ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_2 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 15793693271487750372ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_3 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 11070622951399831030ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_4 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 11187538616904316132ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_5 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 7968519032371426128ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_6 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 9912405421510277680ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_7 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 2863852142972553182ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_8 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 6810301502482034161ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_9 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 16704441562098662382ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_10 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 9762578500864445529ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_11 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 345210578946238066ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_12 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 4242402182037762899ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_13 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 9981455248885718849ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_14 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 9625003507608929350ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_15 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 11930431636373083946ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_16 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 1009012978899570977ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_17 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 4569736780596238861ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_18 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 4181720033835186631ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_19 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 8187863374537648557ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_20 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 14571217730140307749ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_21 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 15724895055702503959ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_22 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 6960495774737859129ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_23 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 4593506886847223646ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_24 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 4857228698717172669ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_25 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 8863372039419610247ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_26 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 17892748191210811170ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_27 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 827798080446975123ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_28 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 14552731793457821735ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_29 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 15934525756403555388ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_30 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 17733246723927159570ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_sums_31 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 55084955619617258ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18266852916146960714ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__stage3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1596817845605789182ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_result_REG = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16293302940207439702ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__io_resultValid_REG = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13322672898330839452ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17266929742442461930ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_0 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1454343723258453294ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_1 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13354725870865029385ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_2 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17268530553392105460ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_3 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15630907071071542227ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_4 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12767785528592270146ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_5 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1729555997037684803ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_6 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13939942639847233155ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_7 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7440094374020887730ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_8 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1887280761041424444ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_9 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12343187204796576913ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_10 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8289014475340272ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_11 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10837699465703877024ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_12 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8425429267270441979ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_13 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11926196961254566291ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_14 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 18241803348887435075ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_15 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 5888724185918360026ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_16 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9948607782247455445ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_17 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1840054466721080650ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_18 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6722712625391788503ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_19 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10760888639144139595ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_20 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8810405639859475598ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_21 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8779375233255293457ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_22 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13651361454637051461ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_23 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9996438116224015037ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_24 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 18173377837813270923ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_25 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15402190470695915926ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_26 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10281003371833547628ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_27 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6730402417012300308ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_28 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7631354793182352238ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_29 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14579353065082545234ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_30 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10818815243651390225ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_31 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 12452877896452993520ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_32 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16524918155349632756ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_33 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4598599335702576228ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_34 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 517030925676587109ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_35 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 6486477380792945113ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_36 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 17707918239886717489ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_37 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 17749864106331865237ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_38 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16282360434738455874ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_39 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 17769092453979691268ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_40 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15933633113453571619ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_41 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14305785676670416376ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_42 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14652614625153702262ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_43 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15104852401213821899ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_44 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 17047473604444257943ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_45 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 18177488438229549883ull);
    vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk1__DOT___GEN_46 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 13459808293640325367ull);
    for (int __Vi0 = 0; __Vi0 < 71; ++__Vi0) {
        vlSelf->DLinearTop__DOT__trendLayer__DOT__unnamedblk2__DOT___RANDOM[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 801862478788377431ull);
    }
    vlSelf->DLinearTop__DOT__seasLayer__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11412748347960218465ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9352510546434144192ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1994448201007359798ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 339231333712524388ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10633126705820103430ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_4 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15908982761667925731ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_5 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1659745687621455591ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_6 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1737014344639678581ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_7 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4820301033384973969ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_8 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1368570287911785302ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_9 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18160699908556286669ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_10 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8053698346929553159ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_11 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12520018461348130043ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_12 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4623212180051441446ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_13 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16106409616632981513ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_14 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6524720254356258098ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_15 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16808917756431767260ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_16 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3094234087478168307ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_17 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13488266891484077761ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_18 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 791413898082553203ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_19 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7052452395411818523ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_20 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9718385387111270602ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_21 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17848708728777804389ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_22 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4134025059824209153ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_23 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11399448566140864398ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_24 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16131508970896845082ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_25 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2375349808831603166ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_26 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8001959920644515971ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_27 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3077857948630309099ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_28 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1675980726502574469ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_29 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9806304068169111200ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_30 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17171299943242869709ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_31 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3415140781177691690ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_32 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12170360190680003948ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_33 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4117648920976350330ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_34 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2592490730353551835ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_35 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9743484741374872436ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_36 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14589974641426076131ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_37 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10645202000057172949ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_38 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 97628973699718140ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_39 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11580826410281466299ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_40 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6760891000389019547ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_41 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10783275713720913539ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_42 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15629765613772117012ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_43 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11684992972403212546ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_44 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16332273753570907736ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_45 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5235732809766145386ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_46 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14100787521198967359ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_47 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5938240949564829018ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_48 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14926576629492664954ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_49 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2740871053112347457ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_50 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17372064725916946927ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_51 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6275523782112187083ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_52 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17294452653953821352ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_53 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3959257926152013788ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_54 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11710092326666977777ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_55 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3657381056963341059ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_56 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9393826470706607868ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_57 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9951417075674345821ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_58 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2958011974634293079ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_59 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7648596886278687376ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_60 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11884983463662848926ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_61 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1568562731619961412ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_62 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10433617443052794723ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_in_63 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10991208048020403972ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 377693575862877373ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_result = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7877394791654837100ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_resultValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11209817196604843741ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_weightEn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4044554229824677119ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_weightAddr = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 13695937153713392635ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_weightData = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8374560766294153569ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 88792775952201695ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2630925698009187883ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15101560489670518008ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15540920222780493012ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_4 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8796910720855706727ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_5 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15901165995150121383ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_6 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9192468054869551112ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_7 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13723969446010546850ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_8 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5025294902560230373ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_9 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11178315690193350473ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_10 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6883307925550052073ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_11 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6750479781077049614ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_12 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5320001766513933057ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_13 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5187173622041000686ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_14 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13463441253738250322ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_15 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5448835951752315223ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_16 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17182618552800585256ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_17 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13596269398211416272ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_18 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4304475371643183628ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_19 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16036260993074138107ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_20 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11434313135796766910ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_21 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11301484991323798524ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_22 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4588523518662400508ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_23 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18149271588075463627ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_24 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17593482029721841578ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_25 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2142519109228567230ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_26 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 712041094665511900ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_27 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7161343257998172489ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_28 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8855480581889870010ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_29 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7423005587709495014ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_30 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8058062966108335413ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_31 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11053844119324737198ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_32 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1212273348974052083ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_33 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16072668268094352447ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_34 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17345841157722813307ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_35 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10630882705444082792ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_36 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9621369125144370373ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_37 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9488540980671505248ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_38 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12061360720007162855ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_39 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7175364715710600664ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_40 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3757652158553992377ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_41 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17318400227966866030ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_42 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7476829457616242224ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_43 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10472610610832687400ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_44 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13045430350168346239ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_45 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5030825048182378362ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_46 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17185572083493970896ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_47 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10049649196951936115ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_48 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11743786520843658614ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_49 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2874953908156213915ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_50 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 381401988865674039ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_51 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13942150058278530455ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_52 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7229188585617349475ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_53 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 514230133338667894ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_54 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15372628072841644980ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_55 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2954221728201462648ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_56 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1944708147901715236ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_57 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12376846919625232589ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_58 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14949666658960955102ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_59 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17945447812177335273ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_60 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3507057755861707715ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_61 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3374229611388668581ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_62 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7647199489187197208ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__weights_63 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8393053760158266418ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1452278374169436203ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2644228888002203003ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9444705398250321970ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_3 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10636655912083234536ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_4 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4890006194224966068ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_5 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12160357348221603136ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_6 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 271943305711874035ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_7 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4389230057276490661ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_8 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9385113782003575446ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_9 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8996397547990154721ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_10 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14607287667929533359ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_11 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14003454053817923294ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_12 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2496542962490755159ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_13 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15201932895312019134ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_14 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4032090178979105297ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_15 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8803824468964003120ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_16 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10714346308973550966ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_17 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4407064802500394388ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_18 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17050345677244267341ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_19 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16675371053722898039ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_20 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5497974894827350696ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_21 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5123000271306153554ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_22 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17766281146049906192ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_23 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17171635918667707108ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_24 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 635413684967831691ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_25 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12774876252204097097ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_26 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6971413053238531835ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_27 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7267606903867845632ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_28 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14544508261244691409ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_29 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13278694559711638365ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_30 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7687348522044192127ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_31 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7092703294661977928ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_32 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9003225134671538141ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_33 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8062323145565527606ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_34 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9972844985575057495ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_35 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15635418353571687220ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_36 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9831955154606040466ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_37 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3199761935705923623ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_38 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17853579957063392283ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_39 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17249746342951786882ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_40 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13950126729812554129ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_41 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6532335541466633629ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_42 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8442857381476348202ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_43 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14000189640906916027ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_44 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8196726441941400921ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_45 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8146663530846908247ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_46 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16094733362374277443ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_47 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15719758738853188201ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_48 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9916295539887363051ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_49 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10107248281950929162ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_50 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16810668831180161543ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_51 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3921257016901227925ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_52 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16564537891645085743ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_53 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17185643454701268640ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_54 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6015800738368527345ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_55 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11007205632214342329ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_56 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12917727472224109420ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_57 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 28315657945206366ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_58 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12671596532689041140ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_59 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 212337539402895959ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_60 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6485605267639352576ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_61 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7106710830695539252ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_62 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1303247631729894962ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_products_63 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 928273008208624019ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3595781186039711450ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_0 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 17546690089808861023ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_1 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 6319767712105084132ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_2 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 987169340889418523ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_3 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 3003031930839628943ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_4 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 5884826678374030225ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_5 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 5350941512648638588ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_6 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 17670124487200310691ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_7 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 17123623296420198916ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_8 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 2305009479422272654ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_9 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 8088208065434608775ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_10 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 11054441096631278332ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_11 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 18373742561575445784ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_12 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 16734411727289721196ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_13 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 1581265471278002488ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_14 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 11710495681059620679ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_15 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 1004017506557825759ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_16 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 7023754060282165364ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_17 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 2938244452022101449ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_18 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 12251722126439953393ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_19 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 12581463599343912262ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_20 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 7529318912987996942ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_21 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 10401952296422434573ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_22 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 13070369782954357737ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_23 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 15862252323220065702ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_24 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 9138692695596341952ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_25 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 9914702111171208724ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_26 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 117450836823547066ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_27 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 8525139420482214445ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_28 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 8253580082948338947ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_29 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 14174071920903287617ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_30 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 18422473434083558083ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_sums_31 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 12826057245123049640ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15995256917812197192ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__stage3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1140272511945589221ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_result_REG = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12333459503947911824ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__io_resultValid_REG = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11794588560743747201ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3271109550191078333ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_0 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11686691063949171101ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_1 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12247931470646614611ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_2 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7490076651935634363ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_3 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8051317058633078597ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_4 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10109858745668337345ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_5 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17216617692861289410ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_6 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17777858099558487192ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_7 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7653623763480537307ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_8 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2301463405011138643ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_9 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13427670727905211168ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_10 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15085423871056803693ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_11 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1172654352696025885ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_12 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10721095460774202728ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_13 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15497328801724224135ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_14 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17603582066728348442ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_15 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7245466305886194723ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_16 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12029882290808945229ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_17 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2892488643065078628ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_18 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1302711083259500325ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_19 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16204928133318283903ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_20 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 5366168294583085741ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_21 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11261253752879611917ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_22 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10185780579559252866ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_23 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17982156130540357075ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_24 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16062098564360382372ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_25 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9076860750678240005ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_26 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16926200418799689911ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_27 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 537730044035868061ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_28 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3904136842822879426ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_29 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15542665603329664628ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_30 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12662312214358867035ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_31 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15912531680872113377ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_32 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 2915989470164968155ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_33 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8718458231759888219ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_34 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 17081904282503573981ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_35 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8556688528140315664ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_36 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 266124123623495948ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_37 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 11747756739230902482ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_38 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 839194838528689631ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_39 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4916524951215565144ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_40 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15453247917051330124ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_41 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9609647129422258739ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_42 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 3861502862897988027ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_43 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 1905979278748716677ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_44 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14803488947786191594ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_45 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14422768347221265889ull);
    vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk1__DOT___GEN_46 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 3604572069234803404ull);
    for (int __Vi0 = 0; __Vi0 < 71; ++__Vi0) {
        vlSelf->DLinearTop__DOT__seasLayer__DOT__unnamedblk2__DOT___RANDOM[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4949277757832170662ull);
    }
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15931148621298646516ull);
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__io_a = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9160770815218928996ull);
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__io_b = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4992554523151182274ull);
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__io_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5206568797812846759ull);
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__io_result = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9945934081568408987ull);
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__io_resultValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14035937895882915771ull);
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__io_result_REG = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13042773803803417054ull);
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__io_resultValid_REG = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15089968321083094257ull);
    vlSelf->DLinearTop__DOT__fusionAdder__DOT__unnamedblk1__DOT__sum = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 2644248148658502119ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->DLinearTop__DOT__fusionAdder__DOT__unnamedblk2__DOT___RANDOM[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8967470299395485605ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__DLinearTop__DOT__clock__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__DLinearTop__DOT__decomp__DOT__clock__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__DLinearTop__DOT__trendLayer__DOT__clock__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__DLinearTop__DOT__seasLayer__DOT__clock__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__DLinearTop__DOT__fusionAdder__DOT__clock__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
