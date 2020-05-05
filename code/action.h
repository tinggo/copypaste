#pragma once


class Action
{
public:
	virtual bool Do() = 0;
};


class ActionDelete : public Action
{
public:
	ActionDelete( const std::string& path );

	virtual bool Do() override;
};


class ActionCopy : public Action
{
public:
	ActionCopy( const std::string& path );

	virtual bool Do() override;
};