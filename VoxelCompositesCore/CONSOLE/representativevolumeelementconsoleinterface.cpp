#include "representativevolumeelementconsoleinterface.h"
#include "constants.h"
using namespace Controller;

int _EditRVECommand::executeConsoleCommand(const std::vector<std::string> &argv)
{
    if(argv.size() != 1)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    auto _pos = _manager.RVEs.find(argv[0]);
    if(_pos == _manager.RVEs.end())
    {
        getConsole().writeToOutput("Error: Representative Volume Element " +
                                   argv[0] + " doesn't exist.\n");
        return -1;
    }
    else
    {
        _RVEName = argv[0];
        getConsole().writeToOutput("Edit RVE GUI start.\n");
        Q_EMIT signal_editRVEGUIStart(_pos->second);
        return 0;
    }
}

void _EditRVECommand::loadRVE(QString fileName)
{
    std::stringstream _str;
    _str << "loadRVE " << _RVEName << " " << fileName.toLocal8Bit().constData();

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_loadRVEDone();
}

void _EditRVECommand::saveRVE(QString fileName)
{
    std::stringstream _str;
    _str << "saveRVE " << _RVEName << " " << fileName.toLocal8Bit().constData();

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_saveRVEDone();
}

void Controller::_EditRVECommand::cleanRVE()
{
    std::stringstream _str;
    _str << "cleanRVE " << _RVEName;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_cleanRVEDone();
}

void Controller::_EditRVECommand::normalizeUnMaskedRVE()
{
    std::stringstream _str;
    _str << "normalizeUnMaskedRVE " << _RVEName;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_normalizeUnMaskedRVEDone();
}

void Controller::_EditRVECommand::invertUnMaskedRVE()
{
    std::stringstream _str;
    _str << "invertUnMaskedRVE " << _RVEName;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_invertUnMaskedRVEDone();
}

void Controller::_EditRVECommand::cleanMaskRVE()
{
    std::stringstream _str;
    _str << "cleanMaskRVE " << _RVEName;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_cleanMaskRVEDone();
}

void Controller::_EditRVECommand::cleanUnMaskedRVE(float filler)
{
    std::stringstream _str;
    _str << "cleanUnMaskedRVE " << _RVEName << " " << filler;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_cleanUnMaskedRVEDone();
}

void Controller::_EditRVECommand::applyTwoCutMaskInsideRVE(
        float cutLevelA, float cutLevelB)
{
    std::stringstream _str;
    _str << "applyTwoCutMaskInsideRVE " << _RVEName
         << " " << cutLevelA << " "
         << " " << cutLevelB;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_applyTwoCutMaskInsideRVEDone();
}

void Controller::_EditRVECommand::applyTwoCutMaskOutsideRVE(
        float cutLevelA, float cutLevelB)
{
    std::stringstream _str;
    _str << "applyTwoCutMaskOutsideRVE " << _RVEName
         << " " << cutLevelA << " "
         << " " << cutLevelB;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_applyTwoCutMaskOutsideRVEDone();
}

void Controller::_EditRVECommand::addRandomNoiseRVE()
{
    std::stringstream _str;
    _str << "addRandomNoiseRVE " << _RVEName;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_addRandomNoiseRVEDone();
}

void _EditRVECommand::applyGaussianFilterRVE(
        int discreteRadius,
        float ellipsoidScaleFactorX,
        float ellipsoidScaleFactorY,
        float ellipsoidScaleFactorZ,
        bool useDataAsIntensity,
        float intensityFactor,
        bool useRotations,
        float rotationOX,
        float rotationOY,
        float rotationOZ)
{
    std::stringstream _str;
    _str << "applyGaussianFilterRVE " << _RVEName << " "
         << discreteRadius << " "
         << ellipsoidScaleFactorX << " "
         << ellipsoidScaleFactorY << " "
         << ellipsoidScaleFactorZ << " ";
    if(useDataAsIntensity) _str << "true ";
    else _str << "false ";
    _str << intensityFactor << " ";
    if(useRotations) _str << "true ";
    else _str << "false ";
    _str << rotationOX << " "
         << rotationOY << " "
         << rotationOZ;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_applyGaussianFilterRVEDone();
}

void _EditRVECommand::generateOverlappingRandomEllipsoidsIntenseRVE(
        int ellipsoidNum,
        int minRadius,
        int maxRadius,
        float transitionLayerSize,
        float ellipsoidScaleFactorX,
        float ellipsoidScaleFactorY,
        float ellipsoidScaleFactorZ,
        bool useRandomRotations,
        float rotationOX,
        float rotationOY,
        float rotationOZ,
        float coreValue)
{
    std::stringstream _str;
    _str << "generateOverlappingRandomEllipsoidsIntenseRVE " << _RVEName << " "
         << ellipsoidNum << " "
         << minRadius << " "
         << maxRadius << " "
         << transitionLayerSize << " "
         << ellipsoidScaleFactorX << " "
         << ellipsoidScaleFactorY << " "
         << ellipsoidScaleFactorZ << " ";
    if(useRandomRotations) _str << "true ";
    else _str << "false ";
    _str << rotationOX << " "
         << rotationOY << " "
         << rotationOZ << " "
         << coreValue;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_generateOverlappingRandomEllipsoidsIntenseRVEDone();
}

void _EditRVECommand::generateOverlappingRandomBezierCurveIntenseRVE(
        int curveNum,
        int curveOrder,
        int curveApproximationPoints,
        int discreteLength,
        float minScale,
        int curveRadius,
        float pathDeviation,
        float transitionLayerSize,
        bool useRandomRotations,
        float rotationOX,
        float rotationOY,
        float rotationOZ,
        float coreValue)
{
    std::stringstream _str;
    _str << "generateOverlappingRandomBezierCurveIntenseRVE " << _RVEName << " "
         << curveNum << " "
         << curveOrder << " "
         << curveApproximationPoints << " "
         << discreteLength << " "
         << minScale << " "
         << curveRadius << " "
         << pathDeviation << " "
         << transitionLayerSize << " ";
    if(useRandomRotations) _str << "true ";
    else _str << "false ";
    _str << rotationOX << " "
         << rotationOY << " "
         << rotationOZ << " "
         << coreValue;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_generateOverlappingRandomBezierCurveIntenseRVEDone();
}

void _EditRVECommand::generateVoronoiRandomCellsRVE(int cellNum)
{
    std::stringstream _str;
    _str << "generateVoronoiRandomCellsRVE " << _RVEName << " " << cellNum;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_generateVoronoiRandomCellsRVEDone();
}

void _EditRVECommand::generateLayerRVE(
        int bottom,
        int top,
        float coreValue)
{
    std::stringstream _str;
    _str << "generateLayerRVE "
         << _RVEName << " "
         << bottom << " "
         << top << " "
         << coreValue;

    // echo to console output without logging
    getConsole().getOutputStream() << _str.str() << "\n";

    getConsole() << _str.str();

    Q_EMIT signal_generateLayerRVEDone();
}

std::string RepresentativeVolumeElementConsoleInterface::createRVE(
        const std::string &name, int size, float representationSize) noexcept
{
    try
    {
        if(RVEs.find(name) != RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " already exists.\n";
        }
        else if((size >= 2) && ((size & (size - 1)) == 0)) // check power o two
        {
            RVEs.emplace(name, new RepresentativeVolumeElement(size, representationSize));
        }
        else
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Cant create Representative Volume Element with given size.\n";
        }
        return "Representative Volume Element " + name + " created.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}


int RepresentativeVolumeElementConsoleInterface::_CreateRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() < 2 || argv.size() > 3)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    int _size;
    float representationSize = 1.0f;
    if(argv.size() == 3)
    {
        std::stringstream _str{argv[2]};
        if(!(_str >> representationSize))
        {
            getConsole().writeToOutput("wrong <representationSize> argument.\n");
            return -1;
        }
    }
    std::stringstream _str{argv[1]};
    if(_str >> _size)
        getConsole().writeToOutput(_manager.createRVE(argv[0], _size, representationSize));
    else
    {
        getConsole().writeToOutput("Error: wrong <size> argument.\n");
        return -1;
    }
    return 0;
}


std::string RepresentativeVolumeElementConsoleInterface::deleteRVE(
        const std::string &name) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            RVEs.erase(_pos);
        return "Representative Volume Element " + name + " deleted.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_DeleteRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 1)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.deleteRVE(argv[0]));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::saveRVE(
        const std::string &name, const std::string &fileName) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->saveRVEToFile(fileName);
        return "Representative Volume Element " + name + " is saved to " + fileName +"\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}
int RepresentativeVolumeElementConsoleInterface::_SaveRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 2)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.saveRVE(argv[0], argv[1]));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::loadRVE(
        const std::string &name, const std::string &fileName) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->loadRVEFromFile(fileName);
        return "Representative Volume Element " + name + " is loaded from " + fileName +"\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}
int RepresentativeVolumeElementConsoleInterface::_LoadRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 2)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.loadRVE(argv[0], argv[1]));
    return 0;
}

std::string Controller::RepresentativeVolumeElementConsoleInterface::printRVE() noexcept
{
    try
    {
        if(RVEs.empty())
            return "There are no Representative Volume Element (RVE) objects in memory.\n";

        std::stringstream _str;
        int _i = 0;
        for(auto _rve: RVEs)
            _str << " [" << _i++ << "]: " << _rve.first << " "
                 <<  _rve.second->getSize() << " "
                 << _rve.second->getRepresentationSize() << std::endl;
        return _str.str();
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_PrintRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 0)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.printRVE());
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::cleanRVE(
        const std::string &name) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->cleanData();
        return "Representative Volume Element " + name + " cleaned.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_cleanRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 1)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.cleanRVE(argv[0]));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::cleanUnMaskedRVE(
        const std::string &name, float filler) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->cleanUnMaskedData(filler);
        return "Representative Volume Element " + name + " cleaned.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_cleanUnMaskedRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() < 1 || argv.size() > 2)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    else if(argv.size() == 1)
        getConsole().writeToOutput(_manager.cleanUnMaskedRVE(argv[0], 0.0f));
    else
    {
        float _filler;
        std::stringstream _str{argv[1]};
        if(_str >> _filler)
            getConsole().writeToOutput(_manager.cleanUnMaskedRVE(argv[0], _filler));
        else
        {
            getConsole().writeToOutput("Error: wrong <filler> argument.\n");
            return -1;
        }
    }
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::cleanMaskRVE(
        const std::string &name) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->cleanMask();
        return "Representative Volume Element " + name + " mask cleaned.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_cleanMaskRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 1)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.cleanMaskRVE(argv[0]));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::addRandomNoiseRVE(
        const std::string &name) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->addRandomNoise();
        return "Representative Volume Element " + name + " random noise generation done.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_addRandomNoiseRVECommandmmand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 1)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.addRandomNoiseRVE(argv[0]));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::normalizeUnMaskedRVE(
        const std::string &name) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->normalizeUnMasked();
        return "Representative Volume Element " + name + " normalized.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_normalizeUnMaskedRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 1)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.normalizeUnMaskedRVE(argv[0]));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::invertUnMaskedRVE(
        const std::string &name) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->invertUnMasked();
        return "Representative Volume Element " + name + " inverted.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_invertUnMaskedRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 1)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    getConsole().writeToOutput(_manager.invertUnMaskedRVE(argv[0]));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::applyGaussianFilterRVE(
        const std::string &name,
        int discreteRadius,
        float ellipsoidScaleFactorX,
        float ellipsoidScaleFactorY,
        float ellipsoidScaleFactorZ,
        bool useDataAsIntensity,
        float intensityFactor,
        bool useRotations,
        float rotationOX,
        float rotationOY,
        float rotationOZ)
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->applyGaussianFilterCL(
                        discreteRadius,
                        ellipsoidScaleFactorX,
                        ellipsoidScaleFactorY,
                        ellipsoidScaleFactorZ,
                        useDataAsIntensity,
                        intensityFactor,
                        useRotations,
                        rotationOX * M_PI / 180.0f,
                        rotationOY * M_PI / 180.0f,
                        rotationOZ * M_PI / 180.0f);
        return "Representative Volume Element " + name + " Gaussian blur filter applying done.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_applyGaussianFilterRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() < 2 || argv.size() > 11)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    int discreteRadius;
    {
        std::stringstream _str{argv[1]};
        if(!(_str >> discreteRadius))
        {
            getConsole().writeToOutput("wrong <Radius> argument.\n");
            return -1;
        }
    }
    float ellipsoidScaleFactorX = 1.0f;
    float ellipsoidScaleFactorY = 1.0f;
    float ellipsoidScaleFactorZ = 1.0f;
    bool useDataAsIntensity = false;
    float intensityFactor = 1.0f;
    bool useRotations = false;
    float rotationOX = 0.0f;
    float rotationOY = 0.0f;
    float rotationOZ = 0.0f;
    switch(argv.size())
    {
    case 11: {std::stringstream _str{argv[10]};
            if(!(_str >> rotationOZ))
            {
                getConsole().writeToOutput("wrong <rotationOZ> argument.\n");
                return -1;
            }
        }
    case 10: {std::stringstream _str{argv[9]};
            if(!(_str >> rotationOY))
            {
                getConsole().writeToOutput("wrong <rotationOY> argument.\n");
                return -1;
            }
        }
    case 9: {std::stringstream _str{argv[8]};
            if(!(_str >> rotationOX))
            {
                getConsole().writeToOutput("wrong <rotationOX> argument.\n");
                return -1;
            }
        }
    case 8: if(argv[7].compare("true") == 0) useRotations = true;
        else if(argv[7].compare("false") == 0) useRotations = false;
        else
        {
            getConsole().writeToOutput("wrong <useRotations> argument.\n");
            return -1;
        }
    case 7:{std::stringstream _str{argv[6]};
            if(!(_str >> intensityFactor))
            {
                getConsole().writeToOutput("wrong <intensityFactor> argument.\n");
                return -1;
            }
        }
    case 6: if(argv[5].compare("true") == 0) useDataAsIntensity = true;
        else if(argv[5].compare("false") == 0) useDataAsIntensity = false;
        else
        {
            getConsole().writeToOutput("wrong <useDataAsIntensity> argument.\n");
            return -1;
        }
    case 5: {std::stringstream _str{argv[4]};
            if(!(_str >> ellipsoidScaleFactorZ))
            {
                getConsole().writeToOutput("wrong <ScaleFactorZ> argument.\n");
                return -1;
            }
        }
    case 4: {std::stringstream _str{argv[3]};
            if(!(_str >> ellipsoidScaleFactorY))
            {
                getConsole().writeToOutput("wrong <ScaleFactorY> argument.\n");
                return -1;
            }
        }
    case 3: {std::stringstream _str{argv[2]};
            if(!(_str >> ellipsoidScaleFactorX))
            {
                getConsole().writeToOutput("wrong <ScaleFactorX> argument.\n");
                return -1;
            }
        }
    }

    getConsole().writeToOutput(_manager.applyGaussianFilterRVE(
            argv[0],
            discreteRadius,
            ellipsoidScaleFactorX,
            ellipsoidScaleFactorY,
            ellipsoidScaleFactorZ,
            useDataAsIntensity,
            intensityFactor,
            useRotations,
            rotationOX,
            rotationOY,
            rotationOZ));

    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::applyTwoCutMaskInsideRVE(
        const std::string &name, float cutLevelA, float cutLevelB) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->applyTwoCutMaskInside(cutLevelA, cutLevelB);
        return "Representative Volume Element " + name + " mask is set.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_applyTwoCutMaskInsideRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 3)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    float cutLevelA;
    {
        std::stringstream _str{argv[1]};
        if(!(_str >> cutLevelA))
        {
            getConsole().writeToOutput("wrong <cutLevelA> argument.\n");
            return -1;
        }
    }
    float cutLevelB;
    {
        std::stringstream _str{argv[2]};
        if(!(_str >> cutLevelB))
        {
            getConsole().writeToOutput("wrong <cutLevelB> argument.\n");
            return -1;
        }
    }
    getConsole().writeToOutput(_manager.applyTwoCutMaskInsideRVE(
                                   argv[0], cutLevelA, cutLevelB));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::applyTwoCutMaskOutsideRVE(
        const std::string &name, float cutLevelA, float cutLevelB) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->applyTwoCutMaskOutside(cutLevelA, cutLevelB);
        return "Representative Volume Element " + name + " mask is set.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_applyTwoCutMaskOutsideRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 3)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    float cutLevelA;
    {
        std::stringstream _str{argv[1]};
        if(!(_str >> cutLevelA))
        {
            getConsole().writeToOutput("wrong <cutLevelA> argument.\n");
            return -1;
        }
    }
    float cutLevelB;
    {
        std::stringstream _str{argv[2]};
        if(!(_str >> cutLevelB))
        {
            getConsole().writeToOutput("wrong <cutLevelB> argument.\n");
            return -1;
        }
    }
    getConsole().writeToOutput(_manager.applyTwoCutMaskOutsideRVE(
                                   argv[0], cutLevelA, cutLevelB));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::generateOverlappingRandomEllipsoidsIntenseRVE(
        const std::string &name,
        int ellipsoidNum,
        int minRadius,
        int maxRadius,
        float transitionLayerSize,
        float ellipsoidScaleFactorX,
        float ellipsoidScaleFactorY,
        float ellipsoidScaleFactorZ,
        bool useRandomRotations,
        float rotationOX,
        float rotationOY,
        float rotationOZ,
        float coreValue) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->generateOverlappingRandomEllipsoidsIntenseCL(
                        ellipsoidNum,
                        minRadius,
                        maxRadius,
                        transitionLayerSize,
                        ellipsoidScaleFactorX,
                        ellipsoidScaleFactorY,
                        ellipsoidScaleFactorZ,
                        useRandomRotations,
                        rotationOX * M_PI / 180.0f,
                        rotationOY * M_PI / 180.0f,
                        rotationOZ * M_PI / 180.0f,
                        coreValue);
        return "Representative Volume Element " + name + " Overlapping Random Ellipsoids generated.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_generateOverlappingRandomEllipsoidsIntenseRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() < 4 || argv.size() > 13)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    int ellipsoidNum;
    {
        std::stringstream _str{argv[1]};
        if(!(_str >> ellipsoidNum))
        {
            getConsole().writeToOutput("wrong <ellipsoidNum> argument.\n");
            return -1;
        }
    }
    int minRadius;
    {
        std::stringstream _str{argv[2]};
        if(!(_str >> minRadius))
        {
            getConsole().writeToOutput("wrong <minRadius> argument.\n");
            return -1;
        }
    }
    int maxRadius;
    {
        std::stringstream _str{argv[3]};
        if(!(_str >> maxRadius))
        {
            getConsole().writeToOutput("wrong <maxRadius> argument.\n");
            return -1;
        }
    }
    float transitionLayerSize = 1.0f;
    float ellipsoidScaleFactorX = 1.0f;
    float ellipsoidScaleFactorY = 1.0f;
    float ellipsoidScaleFactorZ = 1.0f;
    bool useRandomRotations = false;
    float rotationOX = 0.0f;
    float rotationOY = 0.0f;
    float rotationOZ = 0.0f;
    float coreValue = 1.0f;
    switch(argv.size())
    {
    case 13:{std::stringstream _str{argv[12]};
            if(!(_str >> coreValue))
            {
                getConsole().writeToOutput("wrong <coreValue> argument.\n");
                return -1;
            }
        }
    case 12: {std::stringstream _str{argv[11]};
            if(!(_str >> rotationOZ))
            {
                getConsole().writeToOutput("wrong <rotationOZ> argument.\n");
                return -1;
            }
        }
    case 11: {std::stringstream _str{argv[10]};
            if(!(_str >> rotationOY))
            {
                getConsole().writeToOutput("wrong <rotationOY> argument.\n");
                return -1;
            }
        }
    case 10: {std::stringstream _str{argv[9]};
            if(!(_str >> rotationOX))
            {
                getConsole().writeToOutput("wrong <rotationOX> argument.\n");
                return -1;
            }
        }
    case 9: if(argv[8].compare("true") == 0) useRandomRotations = true;
        else if(argv[8].compare("false") == 0) useRandomRotations = false;
        else
        {
            getConsole().writeToOutput("wrong <useRandomRotations> argument.\n");
            return -1;
        }
    case 8: {std::stringstream _str{argv[7]};
            if(!(_str >> ellipsoidScaleFactorZ))
            {
                getConsole().writeToOutput("wrong <ScaleFactorZ> argument.\n");
                return -1;
            }
        }
    case 7: {std::stringstream _str{argv[6]};
            if(!(_str >> ellipsoidScaleFactorY))
            {
                getConsole().writeToOutput("wrong <ScaleFactorY> argument.\n");
                return -1;
            }
        }
    case 6: {std::stringstream _str{argv[5]};
            if(!(_str >> ellipsoidScaleFactorX))
            {
                getConsole().writeToOutput("wrong <ScaleFactorX> argument.\n");
                return -1;
            }
        }
    case 5: {std::stringstream _str{argv[4]};
            if(!(_str >> transitionLayerSize))
            {
                getConsole().writeToOutput("wrong <transitionLayerSize> argument.\n");
                return -1;
            }
        }
    }

    getConsole().writeToOutput(_manager.generateOverlappingRandomEllipsoidsIntenseRVE(
                                   argv[0],
                               ellipsoidNum,
                               minRadius,
                               maxRadius,
                               transitionLayerSize,
                               ellipsoidScaleFactorX,
                               ellipsoidScaleFactorY,
                               ellipsoidScaleFactorZ,
                               useRandomRotations,
                               rotationOX,
                               rotationOY,
                               rotationOZ,
                               coreValue));

    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::generateOverlappingRandomBezierCurveIntenseRVE(
        const std::string &name,
        int curveNum,
        int curveOrder,
        int curveApproximationPoints,
        int discreteLength,
        float minScale,
        int curveRadius,
        float pathDeviation,
        float transitionLayerSize,
        bool useRandomRotations,
        float rotationOX,
        float rotationOY,
        float rotationOZ,
        float coreValue) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->generateOverlappingRandomBezierCurveIntenseCL(
                        curveNum,
                        curveOrder,
                        curveApproximationPoints,
                        discreteLength,
                        minScale,
                        curveRadius,
                        pathDeviation,
                        transitionLayerSize,
                        useRandomRotations,
                        rotationOX * M_PI / 180.0f,
                        rotationOY * M_PI / 180.0f,
                        rotationOZ * M_PI / 180.0f,
                        coreValue);
        return "Representative Volume Element " + name + " Overlapping Bezier curves generated.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_generateOverlappingRandomBezierCurveIntenseRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() < 8 || argv.size() > 14)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    int curveNum;
    {
        std::stringstream _str{argv[1]};
        if(!(_str >> curveNum))
        {
            getConsole().writeToOutput("wrong <curveNum> argument.\n");
            return -1;
        }
    }
    int curveOrder;
    {
        std::stringstream _str{argv[2]};
        if(!(_str >> curveOrder))
        {
            getConsole().writeToOutput("wrong <curveOrder> argument.\n");
            return -1;
        }
    }
    int curveApproximationPoints;
    {
        std::stringstream _str{argv[3]};
        if(!(_str >> curveApproximationPoints))
        {
            getConsole().writeToOutput("wrong <curveApproximationPoints> argument.\n");
            return -1;
        }
    }
    int discreteLength;
    {
        std::stringstream _str{argv[4]};
        if(!(_str >> discreteLength))
        {
            getConsole().writeToOutput("wrong <discreteLength> argument.\n");
            return -1;
        }
    }
    float minScale;
    {
        std::stringstream _str{argv[5]};
        if(!(_str >> minScale))
        {
            getConsole().writeToOutput("wrong <minScale> argument.\n");
            return -1;
        }
    }
    int curveRadius;
    {
        std::stringstream _str{argv[6]};
        if(!(_str >> curveRadius))
        {
            getConsole().writeToOutput("wrong <curveRadius> argument.\n");
            return -1;
        }
    }
    float pathDeviation;
    {
        std::stringstream _str{argv[7]};
        if(!(_str >> pathDeviation))
        {
            getConsole().writeToOutput("wrong <pathDeviation> argument.\n");
            return -1;
        }
    }
    float transitionLayerSize = 1.0f;
    bool useRandomRotations = false;
    float rotationOX = 0.0f;
    float rotationOY = 0.0f;
    float rotationOZ = 0.0f;
    float coreValue = 1.0f;
    switch(argv.size())
    {
    case 14:{std::stringstream _str{argv[13]};
            if(!(_str >> coreValue))
            {
                getConsole().writeToOutput("wrong <coreValue> argument.\n");
                return -1;
            }
        }
    case 13: {std::stringstream _str{argv[12]};
            if(!(_str >> rotationOZ))
            {
                getConsole().writeToOutput("wrong <rotationOZ> argument.\n");
                return -1;
            }
        }
    case 12: {std::stringstream _str{argv[11]};
            if(!(_str >> rotationOY))
            {
                getConsole().writeToOutput("wrong <rotationOY> argument.\n");
                return -1;
            }
        }
    case 11: {std::stringstream _str{argv[10]};
            if(!(_str >> rotationOX))
            {
                getConsole().writeToOutput("wrong <rotationOX> argument.\n");
                return -1;
            }
        }
    case 10: if(argv[9].compare("true") == 0) useRandomRotations = true;
        else if(argv[9].compare("false") == 0) useRandomRotations = false;
        else
        {
            getConsole().writeToOutput("wrong <useRandomRotations> argument.\n");
            return -1;
        }
    case 9: {std::stringstream _str{argv[8]};
            if(!(_str >> transitionLayerSize))
            {
                getConsole().writeToOutput("wrong <transitionLayerSize> argument.\n");
                return -1;
            }
        }
    }

    getConsole().writeToOutput(_manager.generateOverlappingRandomBezierCurveIntenseRVE(
                                   argv[0],
                               curveNum,
                               curveOrder,
                               curveApproximationPoints,
                               discreteLength,
                               minScale,
                               curveRadius,
                               pathDeviation,
                               transitionLayerSize,
                               useRandomRotations,
                               rotationOX,
                               rotationOY,
                               rotationOZ,
                               coreValue));
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::generateVoronoiRandomCellsRVE(
        const std::string &name, int cellNum) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->generateVoronoiRandomCellsCL(cellNum);
        return "Representative Volume Element " + name + " Voronoi random cells generated.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_generateVoronoiRandomCellsRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() != 2)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    int cellNum;
    std::stringstream _str{argv[1]};
    if(_str >> cellNum)
        getConsole().writeToOutput(_manager.generateVoronoiRandomCellsRVE(
                                       argv[0], cellNum));
    else
    {
        getConsole().writeToOutput("wrong <cellNum> argument.\n");
        return -1;
    }
    return 0;
}

std::string RepresentativeVolumeElementConsoleInterface::generateLayerRVE(
        const std::string &name, int bottom, int top, float coreValue) noexcept
{
    try
    {
        auto _pos = RVEs.find(name);
        if(_pos == RVEs.end())
        {
            _refToConsole.setLastCommandBadState(true);
            return "Error: Representative Volume Element " + name + " doesn't exist.\n";
        }
        else
            _pos->second->generateLayerY(bottom, top, coreValue);
        return "Representative Volume Element " + name + " layer generated.\n";
    }
    catch(std::exception &e)
    {
        return "Error: " + std::string(e.what());
    }
}

int RepresentativeVolumeElementConsoleInterface::_generateLayerRVECommand::executeConsoleCommand(
        const std::vector<std::string> &argv)
{
    if(argv.size() < 3 || argv.size() > 4)
    {
        getConsole().writeToOutput("Error: wrong number of arguments.\n");
        return -1;
    }
    int bottom;
    {
        std::stringstream _str{argv[1]};
        if(!(_str >> bottom))
        {
            getConsole().writeToOutput("wrong <bottomSide> argument.\n");
            return -1;
        }
    }
    int top;
    {
        std::stringstream _str{argv[2]};
        if(!(_str >> top))
        {
            getConsole().writeToOutput("wrong <topSide> argument.\n");
            return -1;
        }
    }
    float coreValue = 1.0f;
    if(argv.size() == 4)
    {
        std::stringstream _str{argv[3]};
        if(!(_str >> coreValue))
        {
            getConsole().writeToOutput("wrong <coreValue> argument.\n");
            return -1;
        }
    }

    getConsole().writeToOutput(_manager.generateLayerRVE(argv[0], bottom, top, coreValue));

    return 0;
}
