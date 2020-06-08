#pragma once


class Timer {
protected:
	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;
	std::chrono::duration<double> time_span;


public:

	Timer() = default;

	~Timer() = default;

	// Starts the timer
	void Start() {
		t1 = std::chrono::high_resolution_clock::now();
	}

	// Stops the timer
	void Stop() {
		t2 = std::chrono::high_resolution_clock::now();
	}

	// Returns the interval between the last Start() and Stop()
	double GetElapsed() {
		time_span = duration_cast<std::chrono::duration<double>>(t2 - t1);
		return time_span.count();
	}

	int GetMinutes() {
		return (int)time_span.count() / 60;
	}

	double GetSeconds() {
		return time_span.count() - ((int)time_span.count() / 60) * 60;
	}
};