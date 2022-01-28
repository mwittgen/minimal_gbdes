#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <vector>
#include <iostream>

//#include "Astrometry.h"
/*#include <map>
#include <memory>
#include <Std.h>
#include "Bounds.h"

#include "NameIndex.h"
#include "PixelMapCollection.h"
*/
// Definitions are: "pixel coords" -> "instrument coords" via Instrument map
// instrument coords -> "world coords" via Exposure map (world coords are in a projection nominally about
//             the exposure's pointing)
// world coords -> ICRS coords via the Exposure's projection
// "field coords" -> ICRS coords via the Field's projection (field coords are sky coords in a
//              projection that is common to all Exposures in a field).
// world coords -> field coords via the Exposure's reprojection map

class Instrument {
public:
    Instrument(std::string name_ = "") : name(name_), nDevices(0), band(name_) {}
    std::string name;
    std::string band;  // "band" could be more generic than instrument name.
    int nDevices;
    std::vector<std::string> deviceNames;    // Names of all devices that exist for this instrument
    std::vector<std::string> mapNames;  // Names of instrument PixelMaps for each device
    // Keep track of range of pixel coords per device
    void addDevice(std::string devName);//, const Bounds<double> &devBounds = Bounds<double>()) {
    /*    deviceNames.append(devName);
        domains.push_back(devBounds);
        mapNames.push_back("");
        nDevices = deviceNames.size();
        Assert(mapNames.size() == nDevices);
        Assert(domains.size() == nDevices);
    }*/
};
/*
// Class that represents a single pointing of the telescope:

class Exposure {
public:
    Exposure(const string &name_, const astrometry::SphericalCoords &coords)
            : name(name_),
              projection(coords.duplicate()),
              airmass(1.),
              exptime(1.),
              mjd(0.),
              apcorr(0.),
              weight(1.),
              magWeight(1.),
              pmTDB(0.),
              observatory(0.),
              astrometricCovariance(0.),
              photometricVariance(0.) {}
    ~Exposure() = default;
    string name;  // The exposure map will have this name too.
    std::unique_ptr<astrometry::SphericalCoords>
            projection;  // Projection relating world coords to sky for exposure
    int field;
    int instrument;
    double airmass;
    double exptime;
    double mjd;
    double apcorr;
    double weight;                    // Relative weight applied to this exposure during fitting
    double magWeight;                 // ...and for photometry.  Usually 1.
    string epoch;                     // string-named observation epoch, for time-evolving solutions
    double pmTDB;                     // Observation time relative to PM reference epoch (yrs)
    astrometry::Vector3 observatory;  // Barycentric ICRS position of observatory
    astrometry::Matrix22
            astrometricCovariance;  // Error atop cataloged meas. error for positions (arcsec ICRS)
    double photometricVariance;     // Additional variance for magnitudes on this exposure.
    // No copying:
    Exposure(const Exposure &rhs) = delete;
    void operator=(const Exposure &rhs) = delete;
    EIGEN_NEW
};

class ExposuresHelper {
public:
    ExposuresHelper(vector<string> expNames_, vector<int> fieldNumbers_, vector<int> instrumentNumbers_,
                    vector<double> ras_, vector<double> decs_, vector<double> airmasses_,
                    vector<double> exposureTimes_, vector<double> mjds_)
            : expNames(expNames_),
              fieldNumbers(fieldNumbers_),
              instrumentNumbers(instrumentNumbers_),
              ras(ras_),
              decs(decs_),
              airmasses(airmasses_),
              exposureTimes(exposureTimes_),
              mjds(mjds_){};
    vector<string> expNames;
    // Index of the exposures' fields:
    vector<int> fieldNumbers;
    // Index of the exposures' instruments;
    vector<int> instrumentNumbers;
    vector<double> ras;
    vector<double> decs;
    vector<double> airmasses;
    vector<double> exposureTimes;
    vector<double> mjds;

    std::vector<std::unique_ptr<Exposure>> getExposuresVector() {
        std::vector<std::unique_ptr<Exposure>> tmpExposures;
        tmpExposures.reserve(expNames.size());
        for (int i = 0; i < expNames.size(); i++) {
            astrometry::Gnomonic gn(
                    astrometry::Orientation(astrometry::SphericalICRS(ras[i], decs[i])));
            std::unique_ptr<Exposure> expo(new Exposure(expNames[i], gn));
            expo->field = fieldNumbers[i];
            expo->instrument = instrumentNumbers[i];
            expo->airmass = airmasses[i];
            expo->exptime = exposureTimes[i];
            expo->mjd = mjds[i];
            tmpExposures.emplace_back(std::move(expo));
        }
        return tmpExposures;
    }
};

// Class that represents an catalog of objects from a single device on single exposure.
// Will have originated from a single bintable HDU that we can access.
// The template argument are SubMap, Detection from either astrometry or photometry.
template <class T1, class T2>
class ExtensionBase {
public:
    ExtensionBase() : map(nullptr), wcs(nullptr), startWcs(nullptr), needsColor(false) {}
    int exposure;
    int device;
    double airmass;  // airmass and apcorr used for nightly priors
    double apcorr;
    double magshift;  // Additive adjustment to all incoming mags (exposure time)

    string wcsName;        // Name of final WCS (and map into field coordinates)
    string mapName;        // Name of photometry map or astrometric map into exposure coords
    T1 *map;               // The map from pixel coordinates to field coordinates.
    astrometry::Wcs *wcs;  // Wcs from pixel coordinates to sky coordinates = basemap + field projection
    std::unique_ptr<astrometry::Wcs> startWcs;  // Input Wcs for this extension (owned by this class)
    bool needsColor;                            // Save info on whether map requires color information.

    std::map<long, T2 *> keepers;  // The objects from this Extension catalog that we will use
    ~ExtensionBase() = default;
};

// Class that represents an catalog of objects from a single device on single exposure
// that will be used solely to extract color information.
// The template argument is Match from either astrometry or photometry
template <class T>
class ColorExtensionBase {
public:
    ColorExtensionBase() {}
    int priority;  // Rank of this catalog in heirarchy of colors.  Lower value takes priority.
    // The objects from this catalog that we will use, and the matches they give colors for:
    std::map<long, T *> keepers;
};
*/
#endif
