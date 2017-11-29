#pragma once

#include "Board.h"
#include <random>

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody(std::mt19937 & rng);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		Color GenerateColor(std::mt19937& rng);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow(std::mt19937 & rng);
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};