# (DEPRECATED replaced by Dynwm) 

## Dynamic wallpaper daemon targeted towards tiling wm managers

## Dependencies
- swaybg
- glibc (or any other C++ compiler tho for others you would have to compile manually)

## Compilation
In the directory simply run `make` <- binary name in this case will be "wall"
to compile manually `g++ *.cc -o {binary_name}`

## Usage
the program works by retrieving the hour from the filename so an example directory would be
- 6.jpg (this will change the wallpaper at 6am)
- 12.jpg (.. at 12pm)
- 15.jpg (.. at 3pm)
- 17.jpg (.. at 15pm)
and so on...
**So to give a certain directory with these folders:**
`./{binary_name} -d -w {directory_name}`



## Plans
- Introduce a way to use minutes (the foundation for this already exists im just too lazy)
- planning to introduce a way to use other wallpaper managers
- Try to find a way to rely on exif data from .heic or .heif files instead of this rudimentary approach
- Move on from using an external wallpaper manager (maybe build one from Cairo or using wayland libs?)
  
