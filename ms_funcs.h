/*
 * ms_funcs.h
 */

#ifndef MS_FUNCS_H_
#define MS_FUNCS_H_

#include <string>

// casacore headers
#include <casa/Arrays.h>
#include <tables/Tables.h>
#include <ms/MeasurementSets.h>

#define FIELD_NAME "Zenith"
// Maybe these should be configurable:
#define ANT_NAME "ANT"
#define STATION_NAME "LWA-OVRO"
#define CORRELATOR_NAME "LEDA512"
#define OBSERVER "Default"
#define PROJECT "Default"
#define TELESCOPE_NAME "OVRO_MMA" // Used by CASA as reference position
#define ANTENNA_TYPE "GROUND-BASED"
#define ANTENNA_MOUNT "X-Y"
#define ANTENNA_DISH_DIAMETER 2.0
#define DEFAULT_INT_TIME 8.33

casacore::MEpoch str2MEpoch(const char *time, double offset);
casacore::MDirection getZenith(const casacore::MPosition &pos, const casacore::MEpoch &epoch);
inline double radians(double degrees);
double seaLevel(double latitude);
casacore::Matrix<double> readAnts(const char *filename, int nAnt);
casacore::Matrix<double> zenithUVWs(casacore::Matrix<double> antPos);
casacore::Matrix<double> itrfAnts(casacore::Matrix<double> antPos, int utmzone);
void utm2latlong(int utmzone, double northing, double easting, double* latitude, double* longitude);
int addSourceTab(casacore::MeasurementSet &ms);
int fillAntTab(casacore::MSAntenna &ant, int nAnt, casacore::Matrix<double> itrfPos);
int fillFeedTab(casacore::MSFeed &feed, int nAnt);
int fillFieldTab(casacore::MSField &field, const casacore::MDirection *dir);
int addField(casacore::MSField &field, const casacore::String &name, casacore::MDirection *dir);
int fillObservationTab(casacore::MSObservation &observation, double startTime, double finishTime);
int fillPointingTab(casacore::MSPointing &pointing, int nAnt, double time, const casacore::MDirection *dir);
int fillPolarizationTab(casacore::MSPolarization &polarization);
int fillProcessorTab(casacore::MSProcessor &processor);
int fillSpWindowTab(casacore::MSSpectralWindow &spw, int nFreq, double cFreq, double bw);
int fillSourceTab(casacore::MSSource &source, double startTime, double finishTime, const casacore::MDirection *dir);
int updateSourceTab(casacore::MSSource &source, double startTime, double finishTime);
int updateObservationTab(casacore::MSObservation &observation, double startTime, double finishTime);
void boolArray2charVector(casacore::Array<casacore::Bool> &boolArr, std::vector<char> &charVec);
void charVector2boolArray(std::vector<char> &charVec, casacore::Array<casacore::Bool> &boolArr);
void readCalTable(const char *calName, std::vector<std::complex<float> > &gain, std::vector<char> &flag);

#endif /* MS_FUNCS_H_ */
