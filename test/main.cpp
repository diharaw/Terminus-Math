#include <vec2.h>
#include <mat3.h>
#include <mat4.h>

#include <iostream>

int main(int argc, const char * argv[]) {

	{
		printf("\nvec2 Tests\n\n");

		vec2f a(5.2, 9.1);
		vec2f b(1.3, 15.6);

		vec2f c = a - b;
		c.print();

		vec2f d = a.direction(b);
		d.print();
		printf("length: %f\n", d.length());
	}

	{
		printf("\nvec3 Tests\n\n");

		vec3f a(5.2, 9.1, 1.2);
		vec3f b(1.3, 15.6, 5.1);

		vec3f c = a - b;
		c.print();

		vec3f d = a.direction(b);
		d.print();
		printf("length: %f\n", d.length());

		vec3f j(0.0, 1.0, 0.0);
		vec3f k(0.0, 1.0, 0.0);

		vec3f r = j.cross(k);
		float theta = k.dot(j);

		printf("j x k = ");
		r.print();

		printf("j . k = %f", theta);
	}

	{
		printf("\nvec4 Tests\n\n");

		vec4f a(5.2, 9.1, 1.2, 7.1);
		vec4f b(1.3, 15.6, 5.1, 9.5);

		vec4f c = a - b;
		c.print();
		c = c.normalize();
		printf("length: %f\n", c.length());

		printf("sizeof(vec4f) = %lu\n\n", sizeof(vec4f));
	}

	{
		mat4f a(1, 5, 4, 7,
				3, 9, 3, 2,
				5, 8, 3, 4,
				0, 5, 1, 6);
		a.print();
		printf("\n");

		a = a * 2;

		a.print();
		printf("\n");

		mat4f b = a.transpose();
		b.print();
	}

	std::cin.get();
	return 0;
}
