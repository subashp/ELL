////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     InputNode.h (model)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Node.h"
#include "OutputPort.h"
#include "ModelTransformer.h"

#include <vector>
#include <memory>
#include <string>

/// <summary> model namespace </summary>
namespace model
{
    /// <summary> A node that represents an output from the system. </summary>
    template <typename ValueType>
    class OutputNode : public Node
    {
    public:
        /// <summary> Constructor </summary>
        ///
        /// <param name="input"> The node to get the input data from </param>
        OutputNode(const model::OutputPortElements<ValueType>& input);

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        static std::string GetTypeName() { return utilities::GetCompositeTypeName<ValueType>("OutputNode"); }

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        virtual std::string GetRuntimeTypeName() const override { return GetTypeName(); }

        /// <summary> Exposes the output port as a read-only property </summary>
        const OutputPort<ValueType>& output = _output;

        /// <summary> Makes a copy of this node in the graph being constructed by the transformer </summary>
        virtual void Copy(ModelTransformer& transformer) const override;

        static constexpr const char* inputPortName = "input";
        static constexpr const char* outputPortName = "output";

    protected:
        virtual void Compute() const override;

    private:
        InputPort<ValueType> _input;
        OutputPort<ValueType> _output;
    };
}

#include "../tcc/OutputNode.tcc"
