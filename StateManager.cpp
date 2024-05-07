#include "StateManager.h"
#include "State.hpp"


namespace Engine
{
	StateManager::StateManager() : m_add(false), m_replace(false), m_remove(false)
	{

	}

	StateManager::~StateManager()
	{

	}

	void Add(std::unique_ptr<State> toAdd, bool replace = false)
	{
		m_add = true;
		m_newState = std::move(toAdd);

		m_replace = replace;
	}
	void StateManager::PopCurrent()
	{
		m_remove = true;
	}
	void ProcessStateChange()
	{
		if (m_remove && (!m_stateStack.empty()))
		{
			m_stateStack.pop();

			if (!m_stateStack.empty())
			{
				(m_stateStack.top()->Start();
			}

			m_remove = false;
		}

		if (m_add)
		{
			if (m_remove && (!m_stateStack.empty()))
			{
				m_stateStack.pop();
				m_replace = false();

				if (!m_stateStack.empty())
				{
					(m_stateStack.top()->Pause();
				}

				if (m_stateStack.empty())
				{
					m_stateStack.top()->Pause();
				}

				m_stateStack.push(std::move(m_newState));
				m_add = false;
			}
		}
	}
	std::unique_ptr<State>& GetCurrent()
	{
		return m_stateStack.top();
	}
}