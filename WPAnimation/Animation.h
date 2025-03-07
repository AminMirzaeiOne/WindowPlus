#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace WPAnimation {

	enum AnimationTypes
	{
		Transparent,
	};

	/// <summary>
	/// Summary for Animation
	/// </summary>
	public ref class Animation :  public System::ComponentModel::Component
	{
	public:
		Animation(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Animation(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Required for Windows.Forms Class Composition Designer support
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}



		int i;
		void putprop(int j) {
			i = j;
		}

		int getprop() {
			return i;
		}

		__declspec(property(get = getprop, put = putprop)) int the_prop;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Animation()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			components = gcnew System::ComponentModel::Container();
		}
#pragma endregion
	};
}
