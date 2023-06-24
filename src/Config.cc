//
// Created by fishmarch on 19-5-24.
//

#include "Config.h"

namespace Planar_SLAM{
    void Config::SetParameterFile( const std::string& filename )
    {
        mFile.open( filename.c_str(), cv::FileStorage::READ );
        if ( !mFile.isOpened())
        {
            std::cerr<<"parameter file "<< filename <<" does not exist."<<std::endl;
            mFile.release();
            return;
        }
    }

    Config::~Config()
    {
        if ( mFile.isOpened() )
            mFile.release();
    }
    cv::FileStorage Config::mFile;
}