#include "Math/Vec2.hpp"
#include "Math/Vec3.hpp"
#include "Math/Vec4.hpp"
#include "Math/Vec8.hpp"
#include <iostream>

using namespace drak;
using namespace math;

I32 main() {
	/*drak::math::Vec2i v2i;
	drak::math::Vec2f v2f;

	drak::math::Vec3i v3i;
	drak::math::Vec3f v3f;

	drak::math::Vec4s v4s;
	drak::math::Vec4i v4i;
	drak::math::Vec4f v4f;

	drak::math::Vec8i v8i;
	drak::math::Vec8f v8f;


	//v4i.ceil(); // Doesn't work with Integral Data Type

//////////ADD///////////
	std::cout << "ADDITION :" << "\n";
	std::cout << "v2i += 1 : " << (v2i += 1) << "\n";
	std::cout << "v2f += 1 : " << (v2f += 1) << "\n";
	std::cout << "v3i += 1 : " << (v3i += 1) << "\n";
	std::cout << "v3f += 1 : " << (v3f += 1) << "\n";
	std::cout << "v4s += 1 : " << (v4s += 1) << "\n";
	std::cout << "v4i += 1 : " << (v4i += 1) << "\n";
	std::cout << "v4f += 1 : " << (v4f += 1) << "\n";
	std::cout << "v8i += 1 : " << (v8i += 1) << "\n";
	std::cout << "v8f += 1 : " << (v8f += 1) << "\n";
	std::cout << "v2i += v2i : " << (v2i += v2i) << "\n";
	std::cout << "v2f += v2f : " << (v2f += v2f) << "\n";
	std::cout << "v3i += v3i : " << (v3i += v3i) << "\n";
	std::cout << "v3f += v3f : " << (v3f += v3f) << "\n";
	std::cout << "v4s += v4s : " << (v4s += v4s) << "\n";
	std::cout << "v4i += v4i : " << (v4i += v4i) << "\n";
	std::cout << "v4f += v4f : " << (v4f += v4f) << "\n";
	std::cout << "v8i += v8i : " << (v8i += v8i) << "\n";
	std::cout << "v8f += v8f : " << (v8f += v8f) << "\n";
	std::cout << "v2i + 1 : " << (v2i = v2i + 1) << "\n";
	std::cout << "v2f + 1 : " << (v2f = v2f + 1) << "\n";
	std::cout << "v3i + 1 : " << (v3i = v3i + 1) << "\n";
	std::cout << "v3f + 1 : " << (v3f = v3f + 1) << "\n";
	std::cout << "v4s + 1 : " << (v4s = v4s + 1) << "\n";
	std::cout << "v4i + 1 : " << (v4i = v4i + 1) << "\n";
	std::cout << "v4f + 1 : " << (v4f = v4f + 1) << "\n";
	std::cout << "v8i + 1 : " << (v8i = v8i + 1) << "\n";
	std::cout << "v8f + 1 : " << (v8f = v8f + 1) << "\n";
	std::cout << "v2i + v2i : " << (v2i = v2i + v2i) << "\n";
	std::cout << "v2f + v2f : " << (v2f = v2f + v2f) << "\n";
	std::cout << "v3i + v3i : " << (v3i = v3i + v3i) << "\n";
	std::cout << "v3f + v3f : " << (v3f = v3f + v3f) << "\n";
	std::cout << "v4s + v4s : " << (v4s = v4s + v4s) << "\n";
	std::cout << "v4i + v4i : " << (v4i = v4i + v4i) << "\n";
	std::cout << "v4f + v4f : " << (v4f = v4f + v4f) << "\n";
	std::cout << "v8i + v8i : " << (v8i = v8i + v8i) << "\n";
	std::cout << "v8f + v8f : " << (v8f = v8f + v8f) << "\n\n";

////////////////////////

//////////MUL///////////
	std::cout << "MULTIPLICATION :" << "\n";
	std::cout << "v2i *= 1 : " << (v2i *= 1) << "\n";
	std::cout << "v2f *= 1 : " << (v2f *= 1) << "\n";
	std::cout << "v3i *= 1 : " << (v3i *= 1) << "\n";
	std::cout << "v3f *= 1 : " << (v3f *= 1) << "\n";
	std::cout << "v4s *= 1 : " << (v4s *= 1) << "\n";
	std::cout << "v4i *= 1 : " << (v4i *= 1) << "\n";
	std::cout << "v4f *= 1 : " << (v4f *= 1) << "\n";
	std::cout << "v8i *= 1 : " << (v8i *= 1) << "\n";
	std::cout << "v8f *= 1 : " << (v8f *= 1) << "\n";
	std::cout << "v2i *= v2i : " << (v2i *= v2i) << "\n";
	std::cout << "v2f *= v2f : " << (v2f *= v2f) << "\n";
	std::cout << "v3i *= v3i : " << (v3i *= v3i) << "\n";
	std::cout << "v3f *= v3f : " << (v3f *= v3f) << "\n";
	std::cout << "v4s *= v4s : " << (v4s *= v4s) << "\n";
	std::cout << "v4i *= v4i : " << (v4i *= v4i) << "\n";
	std::cout << "v4f *= v4f : " << (v4f *= v4f) << "\n";
	std::cout << "v8i *= v8i : " << (v8i *= v8i) << "\n";
	std::cout << "v8f *= v8f : " << (v8f *= v8f) << "\n";
	std::cout << "v2i * 1 : " << (v2i = v2i * 1) << "\n";
	std::cout << "v2f * 1 : " << (v2f = v2f * 1) << "\n";
	std::cout << "v3i * 1 : " << (v3i = v3i * 1) << "\n";
	std::cout << "v3f * 1 : " << (v3f = v3f * 1) << "\n";
	std::cout << "v4s * 1 : " << (v4s = v4s * 1) << "\n";
	std::cout << "v4i * 1 : " << (v4i = v4i * 1) << "\n";
	std::cout << "v4f * 1 : " << (v4f = v4f * 1) << "\n";
	std::cout << "v8i * 1 : " << (v8i = v8i * 1) << "\n";
	std::cout << "v8f * 1 : " << (v8f = v8f * 1) << "\n";
	std::cout << "v2i * v2i : " << (v2i = v2i * v2i) << "\n";
	std::cout << "v2f * v2f : " << (v2f = v2f * v2f) << "\n";
	std::cout << "v3i * v3i : " << (v3i = v3i * v3i) << "\n";
	std::cout << "v3f * v3f : " << (v3f = v3f * v3f) << "\n";
	std::cout << "v4s * v4s : " << (v4s = v4s * v4s) << "\n";
	std::cout << "v4i * v4i : " << (v4i = v4i * v4i) << "\n";
	std::cout << "v4f * v4f : " << (v4f = v4f * v4f) << "\n";
	std::cout << "v8i * v8i : " << (v8i = v8i * v8i) << "\n";
	std::cout << "v8f * v8f : " << (v8f = v8f * v8f) << "\n\n";

////////////////////////

//////////DIV///////////
	std::cout << "DIVISION :" << "\n";
	v2i /= 1;
	v2f /= 1;

	v3i /= 1;
	v3f /= 1;

	//v4s /= 1; //not allowed
	v4i /= 1;
	v4f /= 1;

	v8i /= 1;
	v8f /= 1;

	std::cout << "v2i /= 1 : " << v2i << "\n";
	std::cout << "v2f /= 1 : " << v2f << "\n";
	std::cout << "v3i /= 1 : " << v3i << "\n";
	std::cout << "v3f /= 1 : " << v3f << "\n";
	//std::cout << "v4s /= 1 : " << v4s << "\n";
	std::cout << "v4i /= 1 : " << v4i << "\n";
	std::cout << "v4f /= 1 : " << v4f << "\n";
	std::cout << "v8i /= 1 : " << v8i << "\n";
	std::cout << "v8f /= 1 : " << v8f << "\n";

	v2i /= v2i;
	v2f /= v2f;

	v3i /= v3i;
	v3f /= v3f;

	//v4s /= v4s; //not allowed
	v4i /= v4i;
	v4f /= v4f;

	v8i /= v8i;
	v8f /= v8f;

	std::cout << "v2i /= v2i : " << v2i << "\n";
	std::cout << "v2f /= v2f : " << v2f << "\n";
	std::cout << "v3i /= v3i : " << v3i << "\n";
	std::cout << "v3f /= v3f : " << v3f << "\n";
	//std::cout << "v4s /= v4s : " << v4s << "\n";
	std::cout << "v4i /= v4i : " << v4i << "\n";
	std::cout << "v4f /= v4f : " << v4f << "\n";
	std::cout << "v8i /= v8i : " << v8i << "\n";
	std::cout << "v8f /= v8f : " << v8f << "\n";

	v2i = v2i / 1;
	v2f = v2f / 1;

	v3i = v3i / 1;
	v3f = v3f / 1;

	//v4s = v4s / 1; //not allowed
	v4i = v4i / 1;
	v4f = v4f / 1;

	v8i = v8i / 1;
	v8f = v8f / 1;

	std::cout << "v2i / 1 : " << v2i << "\n";
	std::cout << "v2f / 1 : " << v2f << "\n";
	std::cout << "v3i / 1 : " << v3i << "\n";
	std::cout << "v3f / 1 : " << v3f << "\n";
	//std::cout << "v4s / 1 : " << v4s << "\n";
	std::cout << "v4i / 1 : " << v4i << "\n";
	std::cout << "v4f / 1 : " << v4f << "\n";
	std::cout << "v8i / 1 : " << v8i << "\n";
	std::cout << "v8f / 1 : " << v8f << "\n";

	v2i = v2i / v2i;
	v2f = v2f / v2f;

	v3i = v3i / v3i;
	v3f = v3f / v3f;

	//v4s = v4s / v4s; //not allowed
	v4i = v4i / v4i;
	v4f = v4f / v4f;

	v8i = v8i / v8i;
	v8f = v8f / v8f;

	std::cout << "v2i / v2i : " << v2i << "\n";
	std::cout << "v2f / v2f : " << v2f << "\n";
	std::cout << "v3i / v3i : " << v3i << "\n";
	std::cout << "v3f / v3f : " << v3f << "\n";
	//std::cout << "v4s / v4s : " << v4s << "\n";
	std::cout << "v4i / v4i : " << v4i << "\n";
	std::cout << "v4f / v4f : " << v4f << "\n";
	std::cout << "v8i / v8i : " << v8i << "\n";
	std::cout << "v8f / v8f : " << v8f << "\n\n";

////////////////////////

//////////SUB///////////
	std::cout << "SUBSTRACTION :" << "\n";
	std::cout << "v2i -= 1 : " << (v2i -= 1) << "\n";
	std::cout << "v2f -= 1 : " << (v2f -= 1) << "\n";
	std::cout << "v3i -= 1 : " << (v3i -= 1) << "\n";
	std::cout << "v3f -= 1 : " << (v3f -= 1) << "\n";
	std::cout << "v4s -= 1 : " << (v4s -= 1) << "\n";
	std::cout << "v4i -= 1 : " << (v4i -= 1) << "\n";
	std::cout << "v4f -= 1 : " << (v4f -= 1) << "\n";
	std::cout << "v8i -= 1 : " << (v8i -= 1) << "\n";
	std::cout << "v8f -= 1 : " << (v8f -= 1) << "\n";
	std::cout << "v2i -= v2i : " << (v2i -= v2i) << "\n";
	std::cout << "v2f -= v2f : " << (v2f -= v2f) << "\n";
	std::cout << "v3i -= v3i : " << (v3i -= v3i) << "\n";
	std::cout << "v3f -= v3f : " << (v3f -= v3f) << "\n";
	std::cout << "v4s -= v4s : " << (v4s -= v4s) << "\n";
	std::cout << "v4i -= v4i : " << (v4i -= v4i) << "\n";
	std::cout << "v4f -= v4f : " << (v4f -= v4f) << "\n";
	std::cout << "v8i -= v8i : " << (v8i -= v8i) << "\n";
	std::cout << "v8f -= v8f : " << (v8f -= v8f) << "\n";
	std::cout << "v2i - 1 : " << (v2i = v2i - 1) << "\n";
	std::cout << "v2f - 1 : " << (v2f = v2f - 1) << "\n";
	std::cout << "v3i - 1 : " << (v3i = v3i - 1) << "\n";
	std::cout << "v3f - 1 : " << (v3f = v3f - 1) << "\n";
	std::cout << "v4s - 1 : " << (v4s = v4s - 1) << "\n";
	std::cout << "v4i - 1 : " << (v4i = v4i - 1) << "\n";
	std::cout << "v4f - 1 : " << (v4f = v4f - 1) << "\n";
	std::cout << "v8i - 1 : " << (v8i = v8i - 1) << "\n";
	std::cout << "v8f - 1 : " << (v8f = v8f - 1) << "\n";
	std::cout << "v2i - v2i : " << (v2i = v2i - v2i) << "\n";
	std::cout << "v2f - v2f : " << (v2f = v2f - v2f) << "\n";
	std::cout << "v3i - v3i : " << (v3i = v3i - v3i) << "\n";
	std::cout << "v3f - v3f : " << (v3f = v3f - v3f) << "\n";
	std::cout << "v4s - v4s : " << (v4s = v4s - v4s) << "\n";
	std::cout << "v4i - v4i : " << (v4i = v4i - v4i) << "\n";
	std::cout << "v4f - v4f : " << (v4f = v4f - v4f) << "\n";
	std::cout << "v8i - v8i : " << (v8i = v8i - v8i) << "\n";
	std::cout << "v8f - v8f : " << (v8f = v8f - v8f) << "\n\n";

////////////////////////
//////////DIST///////////
	std::cout << "DISTANCE :" << "\n";
	//All Vectors value Should be Zero
	std::cout << "Distance(v2i, { 1, 2 }) : "		<< drak::math::Distance(v2i, { 1, 2 }) << "\n";
	std::cout << "Distance(v2f, { 1.f, 2.f }) : "	<< drak::math::Distance(v2f, { 1.f, 2.f }) << "\n";
	std::cout << "Distance(v3i, { 5, 2, 4 }) : "	<< drak::math::Distance(v3i, { 5, 2, 4 }) << "\n";
	std::cout << "Distance(v3f, { 5.f, 2.f, 4.f }) : "	<< drak::math::Distance(v3f, { 5.f, 2.f, 4.f }) << "\n";
	std::cout << "Distance(v4s, { 1, 1, 1, 1 }) : " << drak::math::Distance(v4s, { 1, 1, 1, 1 }) << "\n";
	std::cout << "Distance(v4i, { 1, 1, 1, 1 }) : " << drak::math::Distance(v4i, { 1, 1, 1, 1 }) << "\n";
	std::cout << "Distance(v4f, { 1, 1, 1, 1 }) : " << drak::math::Distance(v4f, { 1.f, 1.f, 1.f, 1.f }) << "\n\n";
////////////////////////
//////////DOT///////////
	std::cout << "DOT PRODUCT :" << "\n";
	v2i += 1;
	v2f += 1;

	v3i += 1;
	v3f += 1;

	v4s += 1;
	v4i += 1;
	v4f += 1;
	std::cout << "Dot(v2i, { 1, 1}) : "			<<drak::math::Dot(v2i, { 1, 1 }) << "\n";
	std::cout << "Dot(v2f, { 1.f, 1.f}) : "		<<drak::math::Dot(v2f, { 1.f, 1.f }) << "\n";
	std::cout << "Dot(v3i, { 1, 3, 1}) : "		<<drak::math::Dot(v3i, { 1, 3, 1 }) << "\n";
	std::cout << "Dot(v3f, { 1.f, 1.f, 1.f}) : " << drak::math::Dot(v3f, { 1.f, 1.f, 1.f }) << "\n";
	std::cout << "Dot(v4s, { 1, 1, 1, 6}) : "		<<drak::math::Dot(v4s, { 1, 1, 1, 6 }) << "\n";
	std::cout << "Dot(v4i, { 1, 8, 1, 9}) : "		<<drak::math::Dot(v4i, { 1, 8, 1, 9 }) << "\n";
	std::cout << "Dot(v4f, { 1.f, 5.f, 1.f, 2.f}) : "<<drak::math::Dot(v4f, { 1.f, 5.f, 1.f, 2.f }) << "\n\n";
////////////////////////
//////////CROSS///////////
	std::cout << "CROSS PRODUCT :" << "\n";
	std::cout << "Cross(v2i, { 1, 1}) : " << drak::math::Cross(v2i, { 1, 1 }) << "\n";
	std::cout << "Cross(v2f, { 1.f, 1.f}) : " << drak::math::Cross(v2f, { 1.f, 1.f }) << "\n";
	std::cout << "Cross(v3i, { 1, 0, 1}) : " << drak::math::Cross(v3i, { 1, 0, 1 }) << "\n";
	std::cout << "Cross(v3f, { 1.f, 1.f, 0.f}) : " << drak::math::Cross(v3f, { 1.f, 1.f, 0.f }) << "\n";
	std::cout << "Cross(v4s, { 1, 1, 0, 1}) : " << drak::math::Cross(v4s, { 1, 1, 0, 1 }) << "\n";
	std::cout << "Cross(v4i, { 1, 0, 1, 1}) : " << drak::math::Cross(v4i, { 1, 0, 1, 1 }) << "\n";
	std::cout << "Cross(v4f, { 0.f, 1.f, 1.f, 1.f}) : " << drak::math::Cross(v4f, { 0.f, 1.f, 1.f, 1.f }) << "\n\n";
////////////////////////

//////////EQUALITY///////////
	std::cout << "EQUALITY :" << "\n";
	std::cout << "Equal(v4s, { 1, 1, 0, 1}) : " << (v4s == drak::math::Vec4si(1, 1, 0, 1)) << "\n";
	std::cout << "Equal(v4i, { 1, 0, 1, 1}) : " << (v4i == drak::math::Vec4i(1, 0, 1, 1)) << "\n";
	std::cout << "Equal(v4f, { 0.f, 1.f, 1.f, 1.f}) : " << (v4f == drak::math::Vec4f(0.f, 1.f, 1.f, 1.f)) << "\n";
	std::cout << "Equal(v8i, { 1, 0, 1, 1, 0, 1, 1, 6}) : " <<
		(v8i == drak::math::Vec8i(1, 0, 1, 1, 0, 1, 1, 6)) << "\n";
	std::cout << "Equal(v8f, { 0.f, 1.f, 1.f, 1.f, 2.f, 8.f, 1.f, 0.f}) : " <<
		(v8f == drak::math::Vec8f(0.f, 1.f, 1.f, 1.f, 2.f, 8.f, 1.f, 0.f)) << "\n";

	v4s = drak::math::Vec4si(1, 1, 0, 1);
	v4i = drak::math::Vec4i(1, 0, 1, 1);
	v4f = drak::math::Vec4f(0.f, 1.f, 1.f, 1.f);
	v8i = drak::math::Vec8i(1, 0, 1, 1, 0, 1, 1, 6);
	v8f = drak::math::Vec8f(0.f, 1.f, 1.f, 1.f, 2.f, 8.f, 1.f, 0.f);

	std::cout << "Equal(v4s, { 1, 1, 0, 1}) : " << (v4s == drak::math::Vec4si(1, 1, 0, 1)) << "\n";
	std::cout << "Equal(v4i, { 1, 0, 1, 1}) : " << (v4i == drak::math::Vec4i(1, 0, 1, 1)) << "\n";
	std::cout << "Equal(v4f, { 0.f, 1.f, 1.f, 1.f}) : " << (v4f == drak::math::Vec4f(0.f, 1.f, 1.f, 1.f)) << "\n";
	std::cout << "Equal(v8i, { 1, 0, 1, 1, 0, 1, 1, 6}) : " <<
		(v8i == drak::math::Vec8i(1, 0, 1, 1, 0, 1, 1, 6)) << "\n";
	std::cout << "Equal(v8f, { 0.f, 1.f, 1.f, 1.f, 2.f, 8.f, 1.f, 0.f}) : " <<
		(v8f == drak::math::Vec8f(0.f, 1.f, 1.f, 1.f, 2.f, 8.f, 1.f, 0.f)) << std::endl;
////////////////////////*/

	system("pause");
	return 0;
}


//////////////CHRONO/////////////////
/*auto Start = std::chrono::high_resolution_clock::now();
auto Stop = std::chrono::high_resolution_clock::now();
std::cout << " SSE + : " << std::chrono::duration_cast<std::chrono::milliseconds>(Stop - Start).count() << std::endl;

Start = std::chrono::high_resolution_clock::now();
Stop = std::chrono::high_resolution_clock::now();
std::cout << " naive + : " << std::chrono::duration_cast<std::chrono::milliseconds>(Stop - Start).count() << std::endl;*/