#ifndef ZCL_APP_H
#define ZCL_APP_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * INCLUDES
 */
#include "version.h"
#include "zcl.h"


/*********************************************************************
 * CONSTANTS
 */

// Application Events
#define APP_REPORT_EVT                  0x0001
#define APP_READ_SENSORS_EVT            0x0002


#ifdef OUTDOOR_LONG_RANGE
#define APP_REPORT_DELAY ((uint32) 300000) //5 minutes
#else
#define APP_REPORT_DELAY ((uint32) 60000) //1 minute  
#endif



/*********************************************************************
 * MACROS
 */

#define R           ACCESS_CONTROL_READ
#define RR          (R | ACCESS_REPORTABLE)

#define BASIC       ZCL_CLUSTER_ID_GEN_BASIC
#define POWER_CFG   ZCL_CLUSTER_ID_GEN_POWER_CFG
#define TEMP        ZCL_CLUSTER_ID_MS_TEMPERATURE_MEASUREMENT
#define HUMIDITY    ZCL_CLUSTER_ID_MS_RELATIVE_HUMIDITY
#define PRESSURE    ZCL_CLUSTER_ID_MS_PRESSURE_MEASUREMENT

#define ZCL_UINT8   ZCL_DATATYPE_UINT8
#define ZCL_UINT16  ZCL_DATATYPE_UINT16
#define ZCL_UINT32  ZCL_DATATYPE_UINT32
#define ZCL_INT16   ZCL_DATATYPE_INT16
#define ZCL_INT8    ZCL_DATATYPE_INT8

#define ATTRID_MS_RELATIVE_HUMIDITY_MEASURED_VALUE_RAW_ADC              0x0200
#define ATTRID_MS_RELATIVE_HUMIDITY_MEASURED_VALUE_BATTERY_RAW_ADC      0x0201

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * VARIABLES
 */

extern SimpleDescriptionFormat_t zclApp_FirstEP;
//extern SimpleDescriptionFormat_t zclApp_SecondEP;

extern uint8 zclApp_BatteryVoltage;
extern uint8 zclApp_BatteryPercentageRemainig;
extern uint16 zclApp_BatteryVoltageRawAdc;
extern int16 zclApp_Temperature_Sensor_MeasuredValue;
extern int16 zclApp_PressureSensor_MeasuredValue;
extern int16 zclApp_PressureSensor_ScaledValue;
extern int8 zclApp_PressureSensor_Scale;
extern uint16 zclApp_HumiditySensor_MeasuredValue;

// attribute list
extern CONST zclAttrRec_t zclApp_AttrsFirstEP[];
extern CONST uint8 zclApp_AttrsFirstEPCount;

extern const uint8 zclApp_ManufacturerName[];
extern const uint8 zclApp_ModelId[];
extern const uint8 zclApp_PowerSource;

// APP_TODO: Declare application specific attributes here

/*********************************************************************
 * FUNCTIONS
 */

/*
 * Initialization for the task
 */
extern void zclApp_Init(byte task_id);

/*
 *  Event Process for the task
 */
extern UINT16 zclApp_event_loop(byte task_id, UINT16 events);

void user_delay_ms(uint32_t period);

#ifdef __cplusplus
}
#endif

#endif /* ZCL_APP_H */
