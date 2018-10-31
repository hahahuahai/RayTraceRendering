# demo简介
这个光线追踪渲染器是根据[这个博客的JavaScript版本](https://www.cnblogs.com/miloyip/archive/2010/03/29/1698953.html)改编而成的。此程序为C++版本，基于VS2017。大家在看代码之前最好阅读以下原作者的博文，以便更容易理解本代码。
# 重要类的说明
- **三维向量类**：Vector，用(x,y,z)表示。可以表示向量或者点。
- **光线类**：Ray，用一个起点o和一个方向d表示。
- **几何基类**：Geometry，用作被场景中的几何体继承。具体在此程序中被sphere和plane类继承。
- **平面类**：plane，用作平面模型。
- **球体类**：sphere，用作球体模型。
- **并集类**：union，把做个几何物体结合起来，光线要找到一组几个图形的最近交点时使用。
- **透视相机类**：perspectivecamera，用作主视点。
- **相交结果类**：ItersectResult，用于存储几何物件(geometry)、距离(distance)、位置(position)和法向量(normal)。
- **颜色类**：Color，用于记录颜色的RGB信息。
- **材质类**：material，定义交点向某方向(如视点的方向)发出的光的颜色。
- **格子材质类**：CheckerMaterial，继承于material，用于表现格子的材质。
- **Phong材质类**：PhongMaterial，继承于material，用于表现球体的材质。
- **渲染类**：Renderer，用于选择渲染模式。目前有四种，分别是深度渲染、法线渲染、不带反射的光线追踪渲染和带反射的光线追踪渲染。
