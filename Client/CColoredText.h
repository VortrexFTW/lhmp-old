// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#ifndef __CCOLOREDTEXT_H
#define __CCOLOREDTEXT_H

struct CColoredStruct
{
	CColoredStruct* next;
	unsigned int	color;
	unsigned int	width;
	wchar_t*		text;
	CColoredStruct()
	{
		next = NULL;
		color = NULL;
		width = NULL;
		text = NULL;
	}
	CColoredStruct(CColoredStruct* _next, unsigned int _color, unsigned int _width, wchar_t* _text)
	{
		next = _next;
		color = _color;
		width =_width;
		// copy the text
		unsigned int len = wcslen(_text);
		text = new wchar_t[len+1];
		wcscpy(text, _text);
		text[len] = '\0';
	}
};

class CColoredText{
private:
	unsigned int wholeLength;
	unsigned int wholeWidth;
	unsigned int elementsCount;
	CColoredStruct*		start;

	// getting
	CColoredStruct*		pointer;


	void		MakeBlocksFromText(wchar_t* input);
	wchar_t*	FindNextColor(wchar_t* input);
	void		CreateBlock(wchar_t* input, unsigned int length, unsigned int color);
	void		GetBlocksLength();
public:

	CColoredText();
	CColoredText(wchar_t* input);
	~CColoredText();

	/**
		Splits the text into a line with desired width

		@param width the desired line width
		@param wordWrap whether it should wrap words split by character length
		@return a new CColoredText holding the rest of text or NULL
	*/
	CColoredText* SplitText(unsigned int width, bool wordWrap);

	void	PushBlock(CColoredStruct* block);

	void				StartGetting();
	CColoredStruct*		GetNext();

	void	ReCalculate();

	int GetElementCount();
};
#endif