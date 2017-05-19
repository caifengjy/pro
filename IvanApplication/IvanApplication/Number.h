#pragma once
class CNumber
{
public:
	size_t m_number[MATCH_COUNT];

public:
	CNumber();
	CNumber(size_t a0, size_t a1, size_t a2, size_t a3, size_t a4, size_t a5, size_t a6, size_t a7, size_t a8, size_t a9, size_t a10, size_t a11, size_t a12, size_t a13);
	~CNumber();
	string getString();
	CString getCString();
	int Compare(CNumber ratio);
	bool CompareRatio(CNumber ratio);
	int CompareVector(vector<vector<int>> &vecSelNum);
};

