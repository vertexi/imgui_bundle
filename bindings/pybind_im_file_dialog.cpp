#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <pybind11/numpy.h>

#include "hello_imgui/hello_imgui_include_opengl.h"

#include "ImFileDialog/ImFileDialog.h"  // Change this include to the library you are binding

namespace py = pybind11;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void im_file_dialog_setup_texture_loader()
{
	// ImFileDialog requires you to set the CreateTexture and DeleteTexture
	ifd::FileDialog::Instance().CreateTexture = [](uint8_t* data, int w, int h, char fmt) -> void* {
		GLuint tex;

		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, (fmt == 0) ? GL_BGRA : GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		return (void*)tex;
	};

	ifd::FileDialog::Instance().DeleteTexture = [](void* tex) {
		GLuint texID = (GLuint)((uintptr_t)tex);
		glDeleteTextures(1, &texID);
	};
}


void py_init_module_im_file_dialog(py::module& m)
{
	im_file_dialog_setup_texture_loader();

	py::class_<std::filesystem::path>(m, "Path")
		.def(py::init<std::string>())
		.def("__str__", [](const std::filesystem::path& self) { return self.string(); })
		.def("path", [](const std::filesystem::path& self) { return self.string(); })
		.def("filename", [](const std::filesystem::path& self) { return self.filename().string(); })
		.def("extension", [](const std::filesystem::path& self) { return self.extension().string(); })
		.def("parent_path", [](const std::filesystem::path& self) { return self.parent_path(); })
		;
	py::implicitly_convertible<std::string, std::filesystem::path>();

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:ImFileDialog.h>    ////////////////////
    auto pyClassFileDialog =
        py::class_<ifd::FileDialog>
            (m, "FileDialog", "");

    { // inner classes & enums of FileDialog
        auto pyClassFileDialog_ClassFileTreeNode =
            py::class_<ifd::FileDialog::FileTreeNode>
                (pyClassFileDialog, "FileTreeNode", "")
            .def(py::init<const std::string &>(),
                py::arg("path"))
            .def_readwrite("path", &ifd::FileDialog::FileTreeNode::Path, "")
            .def_readwrite("read", &ifd::FileDialog::FileTreeNode::Read, "")
            .def_readwrite("children", &ifd::FileDialog::FileTreeNode::Children, "")
            ;
        auto pyClassFileDialog_ClassFileData =
            py::class_<ifd::FileDialog::FileData>
                (pyClassFileDialog, "FileData", "")
            .def(py::init<const std::filesystem::path &>(),
                py::arg("path"))
            .def_readwrite("path", &ifd::FileDialog::FileData::Path, "")
            .def_readwrite("is_directory", &ifd::FileDialog::FileData::IsDirectory, "")
            .def_readwrite("size", &ifd::FileDialog::FileData::Size, "")
            .def_readwrite("date_modified", &ifd::FileDialog::FileData::DateModified, "")
            .def_readwrite("has_icon_preview", &ifd::FileDialog::FileData::HasIconPreview, "")
            .def_readwrite("icon_preview", &ifd::FileDialog::FileData::IconPreview, "")
            .def_readwrite("icon_preview_data", &ifd::FileDialog::FileData::IconPreviewData, "")
            .def_readwrite("icon_preview_width", &ifd::FileDialog::FileData::IconPreviewWidth, "")
            .def_readwrite("icon_preview_height", &ifd::FileDialog::FileData::IconPreviewHeight, "")
            ;
    } // end of inner classes & enums of FileDialog

    pyClassFileDialog
        .def_static("instance",
            &ifd::FileDialog::Instance, pybind11::return_value_policy::reference)
        .def(py::init<>())
        .def("save",
            &ifd::FileDialog::Save, py::arg("key"), py::arg("title"), py::arg("filter"), py::arg("starting_dir") = "")
        .def("open",
            &ifd::FileDialog::Open, py::arg("key"), py::arg("title"), py::arg("filter"), py::arg("is_multiselect") = false, py::arg("starting_dir") = "")
        .def("is_done",
            &ifd::FileDialog::IsDone, py::arg("key"))
        .def("has_result",
            &ifd::FileDialog::HasResult)
        .def("get_result",
            &ifd::FileDialog::GetResult)
        .def("get_results",
            &ifd::FileDialog::GetResults)
        .def("close",
            &ifd::FileDialog::Close)
        .def("remove_favorite",
            &ifd::FileDialog::RemoveFavorite, py::arg("path"))
        .def("add_favorite",
            &ifd::FileDialog::AddFavorite, py::arg("path"))
        .def("get_favorites",
            &ifd::FileDialog::GetFavorites)
        .def("set_zoom",
            &ifd::FileDialog::SetZoom, py::arg("z"))
        .def("get_zoom",
            &ifd::FileDialog::GetZoom)
        ;
    ////////////////////    </generated_from:ImFileDialog.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
