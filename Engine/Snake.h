#pragma once

#include "Board.h"

class Snake
{
private: 
	class Segment
	{
	public: 
		void Follow( const Segment& next);
		void InitHead(const Location& loc);
		void InitBody();
		void Draw( Board& brd) const;
		void MoveBy(const Location& delta_loc);
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;

	Location GetNextHeadLocation(const Location& delta_loc) const;

private:
	static constexpr int nSegmentsMax = 100;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};