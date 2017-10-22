#include "StrType.h"
#include <ctype.h>

void StrType::MakeEmpty()
{
	letters[0] = '\n';
}

void GetAlpha(bool skip, char letters[])
{
	char letter;
	int count = 0;

	if (skip)
	{
		std::cin.get(letter);
		while (!isalpha(letter) && std::cin)
			std::cin.get(letter);
	}
	else
		std::cin.get(letter);

	if (!std::cin || !isalpha(letter))
		letters[0] = '\n';
	else
	{
		do
		{
			letters[count] = letter;
			count++;
			std::cin.get(letter);
		} while (isalpha(letter) && std::cin && (count < MAX_CHARS));

		letters[count] = '\n';

		if (count == MAX_CHARS)
			do
			{
				std::cin.get(letter);
			} while (isalpha(letter) && std::cin);
	}
	return;
}

void GetNonWhite(bool skip, char letters[])
{
	char letter;
	int count = 0;

	if (skip)
	{
		std::cin.get(letter);
		while (!isalnum(letter) && std::cin)
			std::cin.get(letter);
	}
	else
		std::cin.get(letter);

	if (!std::cin || !isalnum(letter))
		letters[0] = '\n';
	else
	{
		do
		{
			letters[count] = letter;
			count++;
			std::cin.get(letter);
		} while (isalnum(letter) && std::cin && (count < MAX_CHARS));

		letters[count] = '\n';

		if (count == MAX_CHARS)
			do
			{
				std::cin.get(letter);
			} while (isalnum(letter) && std::cin);
	}
}

void GetTillNew(bool skip, char letters[])
{
	return;
}

void StrType::GetString(bool skip, InType charsAllowed)
{
	switch (charsAllowed)
	{
	case ALPHA_NUM: GetAlphaNum(skip, letters);
		break;
	case ALPHA: GetAlpha(skip, letters);
		break;
	case NON_WHITE: GetNonWhite(skip, letters);
		break;
	case NOT_NEW: GetTillNew(skip, letters);
		break;
	}
}

void GetAlphaNum(bool skip, char letters[])
{
	char letter;
	int count = 0;

	if (skip)
	{
		std::cin.get(letter);
		while (!isalnum(letter) && std::cin)
			std::cin.get(letter);
	}
	else
		std::cin.get(letter);

	if (!std::cin || !isalnum(letter))
		letters[0] = '\n';
	else
	{
		do
		{
			letters[count] = letter;
			count++;
			std::cin.get(letter);
		} while (isalnum(letter) && std::cin && (count < MAX_CHARS));

		letters[count] = '\n';

		if ( count == MAX_CHARS)
			do
			{
				std::cin.get(letter);
			} while (isalnum(letter) && std::cin);
	}
}

StrType::StrType()
{
}


StrType::~StrType()
{
}
