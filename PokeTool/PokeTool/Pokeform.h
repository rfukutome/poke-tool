#pragma once

namespace PokeTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  Typing;
    private: System::Windows::Forms::ComboBox^  pokemonName;
    private: System::Windows::Forms::ComboBox^  pokemonNumber;
    private: System::Windows::Forms::PictureBox^  typeImageOne;
    private: System::Windows::Forms::PictureBox^  typeImageTwo;
    protected:

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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->Typing = (gcnew System::Windows::Forms::Label());
            this->pokemonName = (gcnew System::Windows::Forms::ComboBox());
            this->pokemonNumber = (gcnew System::Windows::Forms::ComboBox());
            this->typeImageOne = (gcnew System::Windows::Forms::PictureBox());
            this->typeImageTwo = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->typeImageOne))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->typeImageTwo))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(69, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(95, 25);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Pokemon";
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            // 
            // Typing
            // 
            this->Typing->AutoSize = true;
            this->Typing->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Typing->Location = System::Drawing::Point(282, 9);
            this->Typing->Name = L"Typing";
            this->Typing->Size = System::Drawing::Size(51, 17);
            this->Typing->TabIndex = 1;
            this->Typing->Text = L"Typing";
            // 
            // pokemonName
            // 
            this->pokemonName->FormattingEnabled = true;
            this->pokemonName->Location = System::Drawing::Point(74, 37);
            this->pokemonName->Name = L"pokemonName";
            this->pokemonName->Size = System::Drawing::Size(169, 21);
            this->pokemonName->TabIndex = 2;
            // 
            // pokemonNumber
            // 
            this->pokemonNumber->FormattingEnabled = true;
            this->pokemonNumber->Location = System::Drawing::Point(17, 37);
            this->pokemonNumber->Name = L"pokemonNumber";
            this->pokemonNumber->Size = System::Drawing::Size(51, 21);
            this->pokemonNumber->TabIndex = 3;
            // 
            // typeImageOne
            // 
            this->typeImageOne->Location = System::Drawing::Point(285, 37);
            this->typeImageOne->Name = L"typeImageOne";
            this->typeImageOne->Size = System::Drawing::Size(79, 21);
            this->typeImageOne->TabIndex = 4;
            this->typeImageOne->TabStop = false;
            // 
            // typeImageTwo
            // 
            this->typeImageTwo->Location = System::Drawing::Point(370, 37);
            this->typeImageTwo->Name = L"typeImageTwo";
            this->typeImageTwo->Size = System::Drawing::Size(79, 21);
            this->typeImageTwo->TabIndex = 5;
            this->typeImageTwo->TabStop = false;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1049, 510);
            this->Controls->Add(this->typeImageTwo);
            this->Controls->Add(this->typeImageOne);
            this->Controls->Add(this->pokemonNumber);
            this->Controls->Add(this->pokemonName);
            this->Controls->Add(this->Typing);
            this->Controls->Add(this->label1);
            this->Name = L"MyForm";
            this->Text = L"PokeTool";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->typeImageOne))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->typeImageTwo))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
    }
    };
}
