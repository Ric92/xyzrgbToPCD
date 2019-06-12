#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

int main(int _argc, char const *_argv[])
{

    if (_argc < 2)
    {
        std::cout << "[text_file] [output_file_name]" << std::endl;
        return -1;
    }

    std::string mapFilePath = _argv[1];
    std::string outputFileName = _argv[2];

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);

    std::cout << "Processing textfile\n";
    std::ifstream infile(mapFilePath);
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        float a, x, y, z;
        uint8_t r, g, b;
        if (!(iss >> x >> y >> z >> a >> r >> g >> b))
            break;

        pcl::PointXYZRGB point(r, g, b);
        point.x = x;
        point.y = y;
        point.z = z;
        cloud->push_back(point);
        //std::cout << "x: " << x << " y: " << y << " z: " << z << "\n";
    }
    if (cloud->size() > 0)
    {
        pcl::io::savePCDFileASCII(outputFileName + ".pcd", *cloud);
        std::cout << "Saved " << cloud->points.size() << " data points to " + outputFileName + ".pcd.\n";
    }
    pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
    viewer.showCloud(cloud);
    while (!viewer.wasStopped())
    {
    }
    return 0;
}
