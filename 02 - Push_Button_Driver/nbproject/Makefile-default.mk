#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=MCAL_Layer/GPIO/HAL_GPIO.c Application.c ECU_Layer/Push_Button/ECU_Push_Button.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/Application.p1 ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d ${OBJECTDIR}/Application.p1.d ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/Application.p1 ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1

# Source Files
SOURCEFILES=MCAL_Layer/GPIO/HAL_GPIO.c Application.c ECU_Layer/Push_Button/ECU_Push_Button.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1: MCAL_Layer/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 MCAL_Layer/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1: ECU_Layer/Push_Button/ECU_Push_Button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Push_Button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1 ECU_Layer/Push_Button/ECU_Push_Button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.d ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1: MCAL_Layer/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 MCAL_Layer/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1: ECU_Layer/Push_Button/ECU_Push_Button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Push_Button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1 ECU_Layer/Push_Button/ECU_Push_Button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.d ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Push_Button/ECU_Push_Button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	@echo Normalizing hex file
	@"C:/Program Files/Microchip/MPLABX/v6.05/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v6.05/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" ${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.hex -o${DISTDIR}/Push_Button_Driver.${IMAGE_TYPE}.hex

endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
