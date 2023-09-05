#pragma once

class RandomIntegerGenerator {
public:
	RandomIntegerGenerator();
public:
	/// <summary>
	/// Return a random integer
	/// </summary>
	/// <returns>An integer of [0, 65535]</returns>
	int next();

	/// <summary>
	/// Return a random integer
	/// </summary>
	/// <param name="ceiling">Maximum value</param>
	/// <returns>An integer of [0, ceiling) </returns>
	int next(int ceiling);

	/// <summary>
	/// Return a random integer
	/// </summary>
	/// <param name="left">Left boudary</param>
	/// <param name="right">Right boundary</param>
	/// <returns>An integer of [left, right]</returns>
	int next(int left, int right);
};