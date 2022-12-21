Raytracer 
=========

This is simple CPU raytracer. It is based on the book "Ray Tracing in One Weekend" by Peter Shirley. The code is written in C++ and only uses the standard library. The code is written in a way that it is easy to understand and modify. The code is not optimized for speed and is not meant to be used in production. It is meant to be used as a learning tool. 

It consists in a raytracing library and a simple application that uses the library. The library is in the `include/rt` folder and the application is in the `apps` folder.

Images
------

![Simple Scene Depth]([https://raw.githubusercontent.com/jsilll/raytracer/master/images/raytracing_in_one_weekend/scene_depth.png](https://raw.githubusercontent.com/jsilll/raytracer/main/images/raytracing_in_one_weekend/scene_depth.png?token=GHSAT0AAAAAAB4JP5QOGM6LSWGPN6QOTAEMY5DUJEQ))
![Simple Scene Normals]([https://raw.githubusercontent.com/jsilll/raytracer/master/images/raytracing_in_one_weekend/scene_normals.png](https://raw.githubusercontent.com/jsilll/raytracer/main/images/raytracing_in_one_weekend/scene_normals.png?token=GHSAT0AAAAAAB4JP5QOXG2OBOSDP2OBLC7GY5DUJOA))

Roadmap:
----------
- [ ] Cleaning CMakelists.txt 
- [ ] Typedefs on Doxygen
- [ ] Code coverage
- [ ] Raytracing in One Weekend
- [ ] Raytracing the Next Week
- [ ] Raytracing the Rest of Your Life
- [ ] Adding support for other image formats

Application / Library Features
------------------------------
- Normal Maps 
- Depth Maps 

Library Documentation
--------------------

The library documentation can be built using Doxygen. The Doxygen will produce a`docs` folder. The documentation can be built using the following command:

    doxygen Doxyfile

Building the Application
------------------------

    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

Application Usage
-----------------
The application can be run with the following command:

    ./raytracer
    --seed=<SEED>
    --width=<WIDTH>
    --height=<HEIGHT>
    --output=<OUTPUT>
    --samples=<SAMPLES>
    --bounces=<BOUNCES>
    --render_type=[normal_map|depth_map]

The `seed` argument is used to seed the random number generator. The `width` and `height` arguments are used to set the width and height of the output image. The `output` argument is used to set the output file name. The `samples` argument is used to set the number of samples per pixel. The `bounces` argument is used to set the number of bounces per ray. The `render_type` argument is used to set the type of render to produce.

There are a few optional arguments that can be passed to the application.

    --max_depth=<MAX_DEPTH>

This argument is useful when `--render_type=depth_map` is set. The `max_depth` argument is used to set the maximum depth for the depth map. The default value is 1.

Contributing
------------

If you want to contribute to this project, please follow the following steps:

1. Fork the project
2. Create a new branch
3. Make your changes
4. Create a pull request
5. Wait for the pull request to be reviewed and merged

License
-------

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

Acknowledgments
---------------

* [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
* [Ray Tracing: The Next Week](https://raytracing.github.io/books/RayTracingTheNextWeek.html)
* [Ray Tracing: The Rest of Your Life](https://raytracing.github.io/books/RayTracingTheRestOfYourLife.html)

Contact
-------

If you have any questions, feel free to contact me via [email](mailto:joaos20014@gmail.com).
